#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdbool.h>

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

//searching in tree in iterative way
//using level order traversal
bool findInTree(node *p, int n) {
  if(!p) return false;
  node *temp;
  q.push(p);
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if (n == temp->data) {
      return true;
    }
    if(temp->left) {
      q.push(temp->left);
    }
    if(temp->right) {
      q.push(temp->right);
    }
  }
  return false;
}

int main() {
  node* root;
  root = create();
  int n;
  printf("\nEnter the number you want to search. ");
  scanf("%d", &n);
  bool res = findInTree(root, n);
  if(res)
    printf("\n%d exists in tree.", n);
  else
    printf("\n%d does not exist in tree.", n);
  return 0;
}
