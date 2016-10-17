#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

//Floyd's cycle finding algorithm
bool isLoopinList(node *h) {
	node *slowPtr = h;
	node *fastPtr = h;
	while(fastPtr && fastPtr->next) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr == fastPtr)
			return true;
	}
	return false;
}

void main() {
  node *head = NULL;
  addNode(&head,45);
  addNode(&head,35);
  addNode(&head,25);
  addNode(&head,15);
  addNode(&head,5);
  node* temp;
  temp = head;
  while (temp->next != NULL) {
  	temp = temp->next;
  }
  temp->next = head->next;
  if(isLoopinList(head))
  	printf("\nThere is a loop in Link List.\n");
  else
  	printf("\nThe loop in List does not exist.\n");
  //printList(head);
}