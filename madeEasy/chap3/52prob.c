#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} node;

void sumList(node*, node*, node**, int*);

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

/**
 *  Here the least significant number is at head
 */
node* addListNumberFromHead(node *h1, node *h2) {
  node *resHead = NULL, *last, *temp;
  int carry = 0, sum;
  while (h1 || h2) {
    temp = (node *)malloc(sizeof(node));
    sum = (h1? h1->data: 0) + (h2? h2->data: 0) + carry;
    temp->data = sum % 10;
    temp->next = NULL;
    carry = sum / 10;
    if(resHead == NULL) {
      resHead = temp;
      last = temp;
    } else {
      last->next = temp;
      last = temp;
    }
    if (h1) {
      h1 = h1->next;
    }
    if (h2) {
      h2 = h2->next;
    }
  }
  if (carry) {
    temp = (node *)malloc(sizeof(node));
    temp->data = carry;
    temp->next = NULL;
    last->next = temp;
  }
  return resHead;
}

void sumList(node *h1, node *h2, node **h3, int *carry) {
  if (h1 == NULL) {
    (*h3)->next = NULL;
    return;
  }
  *h3 = (node*)malloc(sizeof(node));
  sumList(h1->next, h2->next, &(*h3)->next, carry);
  (*h3)->data = ((h1->data) + (h2->data) + *carry) % 10;
  *carry = ((h1->data) + (h2->data) + *carry) / 10;
}

void main() {
  node *head1 = NULL;
  node *head2 = NULL;
  addNode(&head1, 5);
  addNode(&head1, 4);
  addNode(&head1, 3);
  addNode(&head1, 5);
  addNode(&head1, 5);
  addNode(&head2, 5);
  addNode(&head2, 5);
  addNode(&head2, 5);
  addNode(&head2, 5);
  addNode(&head2, 5);
  display(head1);
  printf("\n\n");
  display(head2);
  node *res = addListNumberFromHead(head1, head2);
  printf("\n\n");
  display(res);
}
