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

//using 2 pointers
int getMiddle (node *h) {
  node *slowPtr = h;
  node *fastPtr = h;
  while (fastPtr && fastPtr->next) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  return slowPtr->data;
}

//using a variable and pointer the pointer will be updated when variable value is odd
int getMiddle2( node *h) {
  int count = 0;
  node *mid = h;
  while(h != NULL) {
    if (count % 2 == 1) {
      mid = mid->next;
    }
    h = h->next;
    count++;
  }
  return mid->data;
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
  if (head != NULL) {
    printf("\nThe middle value of List is %d\n", getMiddle(head));
    printf("\nThe middle value of List is %d\n", getMiddle2(head));
  } else {
    printf("\nThe List is empty.\n");
  }
}
