#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
  int data;
  struct nodes *next;
} node;

void addNode(node **h, int n) {
  node *newNode = (node*)malloc(sizeof(node));
  newNode->data = n;
  newNode->next = *h;
  *h = newNode;
}

void print (node *h) {
  node *temp = h;
  while (temp != NULL) {
    printf("-->%d", temp->data);
    temp = temp->next;
  }
}

void insertInSortedList (node **h, int num) {
  node *newNode = (node*)malloc(sizeof(node));
  newNode->data = num;
  if(*h == NULL || (*h)->data >= num) {
    newNode->next = *h;
    *h = newNode;
  } else {
    node *temp = *h;
    while (temp->next && temp->next->data < num) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void main() {
    node *head = NULL;
    addNode(&head, 45);
    addNode(&head, 35);
    addNode(&head, 25);
    addNode(&head, 15);
    addNode(&head, 5);
    print(head);
    int n;
    printf("\n\nEnter the number you want to insert in List: ");
    scanf("%d", &n);
    insertInSortedList(&head, n);
    printf("\n\nThe new Link List is \n\n");
    print(head);
}
