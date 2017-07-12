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
  cout<<"\nEnter data (Enter -1 if no child node) : ";
  cin>>n;
  if(n == -1) {
    return NULL;
  }
  p = (node*)malloc(sizeof(node));
  p->data = n;
  cout<<"\nEnter left child of "<<n;
  p->left = create();
  cout<<"\nEnter right child of "<<n;
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
    cout<<"\nThe deepest node of tree is "<<res->data;
  else
    cout<<"\nTree is Empty";
  return 0;
}
