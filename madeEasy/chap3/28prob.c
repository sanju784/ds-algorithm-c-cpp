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

void print(node *h) {
  while(h != NULL) {
    printf("-->%d", h->data);
    h = h->next;
  }
}

void printReverse(node *h) {
  if(h == NULL)
    return;
  printReverse(h->next);
  printf("-->%d", h->data);
}

void main() {
  node *head = NULL;
  addNode(&head, 5);
  addNode(&head, 15);
  addNode(&head, 25);
  addNode(&head, 35);
  addNode(&head, 45);
  addNode(&head, 55);
  print(head);
  printf("\n");
  printReverse(head);
}
