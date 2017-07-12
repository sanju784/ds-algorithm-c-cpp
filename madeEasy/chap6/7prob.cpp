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

//finding size of tree in iterative way
//using level order traversal
int getSize(node *p) {
  if(!p) return 0;
  node *temp;
  q.push(p);
  int size = 0;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    size++;
    if(temp->left) {
      q.push(temp->left);
    }
    if(temp->right) {
      q.push(temp->right);
    }
  }
  return size;
}

int main() {
  node* root;
  root = create();
  cout<<"\nThere are "<<getSize(root)<<" Nodes in tree.";
  return 0;
}
