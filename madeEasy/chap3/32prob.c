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

void reversePair(node *h) {
  int temp;
  while(h && h->next) {
    temp = h->data;
    h->data = h->next->data;
    h->next->data = temp;
    h = h->next->next;
  }
}

void main() {
  node *head = NULL;
  addNode(&head, 55);
  addNode(&head, 45);
  addNode(&head, 35);
  addNode(&head, 25);
  addNode(&head, 15);
  addNode(&head, 5);
  display(head);
  reversePair(head);
  printf("\n\n");
  display(head);
}
