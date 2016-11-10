#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} node;

void addNode (node **h, int n) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = n;
    newNode->next = *h;
    *h = newNode;
}

void display(node *h) {
  while(h != NULL) {
    printf("-->%d", h->data);
    h = h->next;
  }
}

node* getFractionalNode(node *h, int k) {
  node *k_node = NULL, *temp = h;
  int i = 1;
  while(temp) {
    if(i%k == 0) {
      if(k_node == NULL)
        k_node = h;
      else
        k_node = k_node->next;
    }
    i++;
    temp = temp->next;
  }
  return k_node;
}

void main() {
  node *head = NULL;
  int k;
  node *k_node;
  addNode(&head, 55);
  addNode(&head, 45);
  addNode(&head, 35);
  addNode(&head, 25);
  addNode(&head, 15);
  addNode(&head, 5);
  display(head);
  printf("\n\nEnter the value k : ");
  scanf("%d", &k);
  k_node = getFractionalNode(head, k);
  if(k_node) {
    printf("\n\nThe k th node is %d.", k_node->data);
  } else {
    printf("There is no node at required position.");
  }
}
