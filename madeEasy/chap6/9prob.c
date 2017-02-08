#include <stdio.h>
#include <stdlib.h>

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

//using post order traversal as it will delete both child node first
void deleteTree(node *p) {
  if(p) {
    deleteTree(p->left);
    deleteTree(p->right);
    free(p);
  }
}

void main() {
  node *root;
  root = create();
  deleteTree(root);
}
