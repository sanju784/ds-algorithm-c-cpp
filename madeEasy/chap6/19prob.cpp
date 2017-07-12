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

int levelMaxSum(node *root) {
  if(root == NULL) return 0;
  int level = 0, maxSum = 0, currentSum = 0, maxLevel = 0;
  q.push(root);
  q.push(NULL);
  node *temp;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if (temp == NULL) {
      if (currentSum > maxSum) {
        maxSum = currentSum;
        maxLevel = level;
      }
      currentSum = 0;
      level++;
      if(!q.empty()) {
        q.push(NULL);
      }
    } else {
      currentSum += temp->data;
      if(temp->left) {
        q.push(temp->left);
      }
      if(temp->right) {
        q.push(temp->right);
      }
    }
  }
  return maxLevel;
}

int main() {
  node* root;
  root = create();
  cout<<"\nThe maximum sum of nodes is at level : "<<levelMaxSum(root);
  return 0;
}
