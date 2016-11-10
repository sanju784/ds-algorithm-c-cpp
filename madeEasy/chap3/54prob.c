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

void reverseList(node **h) {
    node *prev = NULL;
    node *current = *h;
    node *next;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *h = prev;
}

void changeList(node *h) {
  node *slowPtr = h, *fastPtr = h->next;
  while (fastPtr && fastPtr->next){
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  reverseList(&slowPtr->next);
  node *temp, *temp2;
  node *midPtr = slowPtr->next;
  slowPtr->next = NULL;
  while (midPtr) {
    temp = h->next;
    h->next = midPtr;
    temp2 = midPtr->next;
    midPtr->next = temp;
    h = temp;
    midPtr = temp2;
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
  changeList(head);
  printf("\n\nNew List is\n");
  display(head);
}
