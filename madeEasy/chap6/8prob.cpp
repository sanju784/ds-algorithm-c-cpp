#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>

using namespace std;

typedef struct tree {
  int data;
  struct tree *left, *right;
} node;

queue <node*> q;
stack <int> stk;

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

void reverseLevelOrder(node *p) {
  node *temp;
  if(p) q.push(p);
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if(temp->right) {
      q.push(temp->right);
    }
    if(temp->left) {
      q.push(temp->left);
    }
    stk.push(temp->data);
  }
}

int main() {
  node* root;
  root = create();
  reverseLevelOrder(root);
  cout<<"\nThe reverse Level traversal is \n";
  while(!stk.empty()) {
    cout<<stk.top()<<" ";
    stk.pop();
  }
  return 0;
}
