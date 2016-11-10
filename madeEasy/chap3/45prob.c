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

node *modularFromBegin(node *h, int k) {
  if (k == 0 || h == NULL)
    return NULL;
  node *mod_node; int i = 1;
  while (h) {
    if(i%k == 0) {
      mod_node = h;
    }
    h = h->next;
    i++;
  }
  return mod_node;
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
  node *res = modularFromBegin(head, k);
  if (res) {
    printf("\n\nResult is %d", res->data);
  } else {
    printf("\n\nEnter correct input.");
  }
}
