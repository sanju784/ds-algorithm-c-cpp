#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
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

int heightOfTree(node *p) {
  int lHeight, rHeight;
  if(p == NULL) {
    return 0;
  } else {
    lHeight = heightOfTree(p->left);
    rHeight = heightOfTree(p->right);
    if(lHeight > rHeight)
      return lHeight + 1;
    else
      return rHeight + 1;
  }
}

void main() {
  node *root;
  root = create();
  printf("\nThe height of tree is %d.", heightOfTree(root));
}
