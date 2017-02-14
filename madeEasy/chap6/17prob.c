#include<stdio.h>
#include<stdlib.h>

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

//When using level order traversal, the mirror case is left unchecked
int treeCompare(node *p1, node *p2) {
  if (p1 == NULL && p2 == NULL) return 1;
  if (p1 != NULL && p2 != NULL)
  return (p1->data == p2->data && treeCompare(p1->left, p2->left) && treeCompare(p2->right, p2->right));
  return 0;
}

void main() {
  printf("\nEnter tree 1\n");
  node *root1 = create();
  printf("\nEnter tree 2\n");
  node *root2 = create();
  if(treeCompare(root1, root2)) {
    printf("\nBoth trees are identical\n");
  } else {
    printf("\nTrees are not identical\n");
  }
}
