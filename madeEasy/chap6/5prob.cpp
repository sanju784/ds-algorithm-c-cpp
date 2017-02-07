#include <iostream>
#include <queue>
#include <stdlib.h>

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

// using level order traversal
// inserting at fist null position
void insertInTree(node *p, int n) {
  node *newNode = (node*)malloc(sizeof(node));
  newNode->data = n;
  newNode->left = NULL;
  newNode->right = NULL;
  if(p) {
    q.push(p);
  } else {
    p = newNode;
  }
  node *temp;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if(temp->left == NULL) {
      temp->left = newNode;
      return;
    } else if(temp->right == NULL) {
      temp->right = newNode;
      return;
    }
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
  }
}

void inOrder(node *p) {
  if(p) {
    inOrder(p->left);
    printf("%d ", p->data);
    inOrder(p->right);
  }
}

int main() {
  node* root;
  root = create();
  int n;
  printf("\nInorder traversal of tree before insertion.\n");
  inOrder(root);
  printf("\nEnter the number you want to insert. ");
  scanf("%d", &n);
  if(root) {
    insertInTree(root, n);
  } else {
    root = (node*)malloc(sizeof(node));
    root->data = n;
    root->left = NULL;
    root->right = NULL;
  }
  printf("\nInorder traversal of tree after insertion.\n");
  inOrder(root);
  return 0;
}
