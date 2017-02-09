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

node* findDeepestNode(node *p) {
  if(!p)return NULL;
  q.push(p);
  node *temp;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if(temp->left)
        q.push(temp->left);
    if(temp->right)
        q.push(temp->right);
  }
  return temp;
}

int main() {
  node* root;
  root = create();
  node *res = findDeepestNode(root);
  if(res)
    printf("\nThe deepest node of tree is %d", res->data);
  else
    printf("\nTree is Empty");
  return 0;
}
