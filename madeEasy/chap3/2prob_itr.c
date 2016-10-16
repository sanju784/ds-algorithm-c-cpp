#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
  int data;
  struct nodes* next;
} node;

void addNode(node **h, int n) {
 node* newNode = (node*)malloc(sizeof(node));
 newNode->data = n;
 newNode->next = (*h);
 (*h) = newNode;
}

void printList(node *h) {
  node *temp;
  temp = h;
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
    if(temp != NULL) {
      printf("-->");
    }
  }
}

void printnFromLast(node *h, int n) {
  node *nthptr, *lastptr;
  nthptr = lastptr = h;
  int count = 0;
  while (lastptr != NULL) {
    if(count >= n) {
      nthptr = nthptr->next;
    }
    lastptr = lastptr->next;
    count++;
  }
  if(count < n) {
    printf("\nThe desired node does not exist.\n");
  } else {
    printf("\nThe nth node from end is %d", nthptr->data);
  }
}

void main() {
    struct nodes *head = NULL;
    addNode(&head, 5);
    addNode(&head, 15);
    addNode(&head, 25);
    addNode(&head, 35);
    addNode(&head, 45);
    printList(head);
    int n;
    printf("\n Enter the nth value you need. ");
    scanf("%d", &n);
    printnFromLast(head, n);
}