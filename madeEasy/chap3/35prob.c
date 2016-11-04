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
    if(*h == NULL) {
      *h = newNode;
      newNode->next = *h;
      return;
    }
    node *temp = *h;
    while (temp->next != *h){
      temp = temp->next;
    }
    temp->next = newNode;
}

void display(node *h) {
  node *temp = h;
  do {
    if(h == NULL) {
      return;
    }
    printf("-->%d", temp->data);
    temp = temp->next;
  } while(temp != h);
}

void splitList(node *h, node **h1, node** h2) {
  node *slowPtr, *fastPtr;
  slowPtr = fastPtr = h;
  while (fastPtr->next != h && fastPtr->next->next != h) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  if(fastPtr->next->next == h) {
    fastPtr = fastPtr->next;
  }
  *h2 = slowPtr->next;
  fastPtr->next = slowPtr->next;
  slowPtr->next = h;
  *h1 = h;
}

void main() {
  node *head = NULL;
  node *head1 = NULL;
  node *head2 = NULL;
  addNode(&head, 5);
  addNode(&head, 15);
  addNode(&head, 25);
  addNode(&head, 35);
  addNode(&head, 45);
  addNode(&head, 55);
  display(head);
  splitList(head, &head1, &head2);
  printf("\n\n");
  display(head1);
  printf("\n\n");;
  display(head2);
}
