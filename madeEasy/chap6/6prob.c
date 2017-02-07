#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct tree{
  int data;
  struct tree *left, *right;
} node;

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

int getSize(node *p) {
  if(p == NULL)
    return 0;
  else
    return getSize(p->left) + getSize(p->right) + 1;
}

void main() {
  node *root;
  root = create();
  printf("\nThere are %d Nodes in tree.", getSize(root));
}
