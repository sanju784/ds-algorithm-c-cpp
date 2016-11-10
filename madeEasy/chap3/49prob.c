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

node* mergeList(node *h1, node *h2) {
  if(h1 == NULL)
    return h2;
  if(h2 == NULL)
    return h1;
  node *h3 = h1;
  node *last = h3;
  h1 = h1->next;
  while (h1 && h2) {
    last->next = h2;
    h2 = h2->next;
    last = last->next;
    last->next = h1;
    h1 = h1->next;
    last = last->next;
  }
  if(h1 == NULL)
    last->next = h2;
  else
    last->next = h1;
  return h3;
}

void main() {
  node *head1 = NULL, *head2 = NULL;
  addNode(&head1, 55);
  addNode(&head1, 45);
  addNode(&head1, 35);
  addNode(&head1, 25);
  addNode(&head1, 15);
  addNode(&head1, 5);
  addNode(&head2, 50);
  addNode(&head2, 40);
  addNode(&head2, 30);
  addNode(&head2, 20);
  addNode(&head2, 10);
  display(head1);
  printf("\n\n");
  display(head2);
  printf("\n\nThe list after merge is \n\n");
  display(mergeList(head1, head2));
}
