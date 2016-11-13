#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} node;

void addSameList(node *, node *, int *, node **);
void addRemainingNumbers(node *, int *, node **, int );

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

void addListFromTail(node* h1, node* h2, node **result) {
  int carry = 0;
  int len1 = 0, len2 = 0, diff, i;
  node *temp;
  temp = h1;
  while (temp) {
    len1++;
    temp = temp->next;
  }
  temp = h2;
  while (temp) {
    len2++;
    temp = temp->next;
  }
  if (len1 < len2) {
    temp = h1;
    h1 = h2;
    h2 = temp;
  }
  temp = h1;
  diff = abs(len1 - len2);
  for (i = 0;i < diff; i++) {
    temp = temp->next;
  }
  addSameList(temp, h2, &carry, result);
  
  addRemainingNumbers(h1, &carry, result, diff);
  if(carry) {
    node *temp = (node*)malloc(sizeof(node*));
    temp->data = carry;
    temp->next = (*result);
    *result = temp;
  }
}

void addSameList(node *h1, node *h2, int *carry, node **result) {
  int sum;
  if(!h1) return;
  addSameList(h1->next, h2->next, carry, result);
  node *temp = (node*)malloc(sizeof(node*));
  sum = (h1->data) + (h2->data) + (*carry);
  *carry = sum / 10;
  sum = sum % 10;
  temp->data = sum;
  temp->next = (*result);
  *result = temp;
}

void addRemainingNumbers(node *h1, int *carry, node **result, int diff) {
  if (!h1 || diff == 0) return;
  int sum = 0;
  addRemainingNumbers(h1->next, carry, result, diff--);
  node *temp = (node*)malloc(sizeof(node*));
  sum = (h1->data) + (*carry);
  *carry = sum / 10;
  sum = sum % 10;
  temp->data = sum;
  temp->next = *result;
  *result = temp;
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
  node *res = NULL;
  addListFromTail(head1, head2, &res);
  printf("\n\n");
  display(res);
}
