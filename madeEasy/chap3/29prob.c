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
  node *temp = h;
  while(temp != NULL) {
    printf("-->%d", temp->data);
    temp = temp->next;
  }
}

char* oddorEven (node *h) {
  while(h && h->next) {
    h = h->next->next;
  }
  if(h)
    return "odd";
  else
    return "even";
}

void main() {
  node *head = NULL;
  addNode(&head, 5);
  addNode(&head, 15);
  addNode(&head, 25);
  addNode(&head, 35);
  addNode(&head, 45);
  addNode(&head, 55);
  display(head);
  printf("\n List has %s number of elements", oddorEven(head));
}
