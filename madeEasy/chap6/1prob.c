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

int getMax(node *p, int max) {
  if(p != NULL) {
    if(p->data > max) {
      max = p->data;
    }
    max = getMax(p->left, max);
    max = getMax(p->right, max);
  }
  return max;
}

void main() {
  node *root;
  root = create();
  if(root)
    printf("\nThe maximum element in tree is %d", getMax(root, INT_MIN));
  else
    printf("\nNo element in tree.");
}
