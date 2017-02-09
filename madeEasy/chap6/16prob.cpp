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

int countHalfNode(node *p) {
  if(!p)return 0;
  q.push(p);
  node *temp;
  int count = 0;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if (temp->left && temp->right) {
      q.push(temp->left);
      q.push(temp->right);
    } else {
      if(temp->left) {
        q.push(temp->left);
        count++;
      }
      if(temp->right) {
        q.push(temp->right);
        count++;
      }
    }
  }
  return count;
}

int main() {
  node* root;
  root = create();
  printf("\nTree has %d half nodes.", countHalfNode(root));
  return 0;
}
