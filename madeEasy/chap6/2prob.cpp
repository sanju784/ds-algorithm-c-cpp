#include <iostream>
#include <queue>
#include <climits>
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

//getting maximum by iterative way using level order traversal
int getMax(node *p) {
  int max = INT_MIN;
  node *temp;
  q.push(p);
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if (max < temp->data) {
      max = temp->data;
    }
    if(temp->left) {
      q.push(temp->left);
    }
    if(temp->right) {
      q.push(temp->right);
    }
  }
  return max;
}

int main() {
  node* root;
  root = create();
  if(root)
    printf("\nThe maximum element in tree is %d", getMax(root));
  else
    printf("\nNo element in tree.");
  return 0;
}
