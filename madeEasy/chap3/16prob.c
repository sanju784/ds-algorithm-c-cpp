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

void reverseListRec(node **h, node* prev, node* current, node *nextP) {
  if(nextP->next == NULL) {
    *h = nextP;
    return;
  }
  current->next = prev;
  prev = current;
  current = nextP;
  nextP = nextP->next;
  reverseList(h, prev, current, nextP);
}

void reverseListItr(node **h, node* prev, node* current, node *nextP) {
 while (1) {
  if(nextP == NULL) {
    *h = current;
    current->next = prev;
    break;
  }
  current->next = prev;
  prev = current;
  current = nextP;
  nextP = nextP->next;
 }
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
  node *prev = NULL, *current = head, *nextP = head->next;
  reverseListItr(&head, prev, current, nextP);
  printf("\n");
  print(head);
}
