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

void segregateList(node **h) {
  node *oddHead = NULL;
  node *evenHead = NULL;
  node *oddEnd, *evenEnd;
  node *temp = *h;
  while (temp) {
    if (temp->data % 2 == 1) {
      if(oddHead == NULL) {
        oddHead = temp;
        oddEnd = temp;
      } else {
        oddEnd->next = temp;
        oddEnd = temp;
      }
    } else {
      if (evenHead == NULL) {
        evenHead = temp;
        evenEnd = temp;
      } else {
        evenEnd->next = temp;
        evenEnd = temp;
      }
    }
    temp = temp->next;
  }
  if(oddHead == NULL)
    *h = evenHead;
  else if(evenHead == NULL)
    *h = oddHead;
  else {
    *h = evenHead;
    evenEnd->next = oddHead;
    oddEnd->next = NULL;
  }
}

void main() {
  node *head = NULL;
  addNode(&head, 5);
  addNode(&head, 10);
  addNode(&head, 25);
  addNode(&head, 20);
  addNode(&head, 15);
  addNode(&head, 50);
  display(head);
  segregateList(&head);
  printf("\n\n");
  display(head);
}
