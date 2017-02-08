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

int findHeightIterative(node *root) {
  if(root == NULL) return 0;
  node *temp;
  int h = 0;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {
    temp = q.front();
    q.pop();
	if(temp == NULL){
	  h++;
	  if(!q.empty()) q.push(NULL);
	} else {
	  if(temp->left)
	    q.push(temp->left);
	  if(temp->right)
	    q.push(temp->right);
	}
  }
  return h;
}

int main() {
  node* root;
  root = create();
  printf("\nThe height of tree is %d", findHeightIterative(root));
  return 0;
}
