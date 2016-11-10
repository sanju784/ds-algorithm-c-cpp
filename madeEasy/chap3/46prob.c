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

node *modularFromEnd(node *h, int k) {
  if (k == 0 || h == NULL)
    return NULL;
  node *n1 = h, *n2 = h;
  int i;
  for (i = 0;i < k; i++) {
    n1 = n1->next;
  }
  while (n1) {
    n1 = n1->next;
    n2 = n2->next;
  }
  return n2;
}

void main() {
  node *head = NULL;
  int k;
  addNode(&head, 55);
  addNode(&head, 45);
  addNode(&head, 35);
  addNode(&head, 25);
  addNode(&head, 15);
  addNode(&head, 5);
  display(head);
  printf("\nEnter the value of k ");
  scanf("%d", &k);
  node *res = modularFromEnd(head, k);
  if (res) {
    printf("\n\nResult is %d", res->data);
  } else {
    printf("\n\nEnter correct input.");
  }
}
