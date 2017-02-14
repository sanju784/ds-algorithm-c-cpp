#include <iostream>
#include <queue>
#include <stdlib.h>
#include <climits>

using namespace std;

typedef struct tree {
  int data;
  struct tree *left, *right;
} node;

queue <node*> q;

node *create() {
  node* p;
  int n;
  printf("\nEnter data (Enter -1 if no child node) : ");
  scanf("%d", &n);
  if(n == -1) {
    return NULL;
  }
  p = (node*)malloc(sizeof(node));
  p->data = n;
  printf("\nEnter left child of %d", n);
  p->left = create();
  printf("\nEnter right child of %d", n);
  p->right = create();
  return p;
}

void inorder(node *p) {
  if (p) {
    inorder(p->left);
    printf("%d ", p->data);
    inorder(p->right);
  }
}

void deleteNode(node *p, int n) {
  if(!p){
    printf("\nTree is empty.\n");
    return;
  }
  if (p->data == n && p->left == NULL && p->right == NULL) {
    p->data = INT_MIN;
    return;
  }
  q.push(p);
  node *ptr, *prnt_node, *last_node, *temp;
  ptr = NULL;
  if(n == p->data) {
    ptr = p;
  }
  prnt_node = p;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if(temp->data == n)
      ptr = temp;
    if(temp->left || temp->right) {
      prnt_node = temp;
    }
    if(temp->left == NULL && temp->right == NULL) {
      last_node = temp;
    }
    if(temp->left) {
      q.push(temp->left);
    }
    if(temp->right) {
      q.push(temp->right);
    }
  }
  if(ptr == NULL) {
    cout<<endl<<n<<" does not exist in tree.\n";
    return;
  }
  ptr->data = last_node->data;
  if(prnt_node->left == last_node)
    prnt_node->left = NULL;
  if(prnt_node->right == last_node)
    prnt_node->right = NULL;
  free(last_node);
}

int main() {
  node* root;
  root = create();
  printf("\nThe Inorder traversal of tree before deletion is \n");
  inorder(root);
  int n;
  printf("\n\nEnter the data of node you want to delete  ");
  scanf("%d", &n);
  deleteNode(root, n);
  if(root->data == INT_MIN) {
    printf("\nTree is now empty.\n");
    free(root);
  } else {
    printf("\nThe Inorder traversal of tree after deletion is \n");
    inorder(root);
  }
  return 0;
}
