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

node* findStartLoopNode(node *h) {
	node *slowPtr = h;
	node *fastPtr = h;
	while(fastPtr && fastPtr->next) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr == fastPtr) {
        /**
         * If loop exists in pointer then start slowPtr from head and fast from where it is
         * for both only take one step at a time following rule of m+k = (x-2y)*n i.e. m+k is multiple of n
         * where m is no. of node before loop k is meeting point of slow and fast pointer and n is no. of nodes in loop
         */
            slowPtr = h;
            while (slowPtr != fastPtr) {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
            }
            return fastPtr;
		}
	}
  return NULL;
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
  node* res = findStartLoopNode(head);
  if(res)
    printf("\nThe node at begin of loop is %d\n", res->data);
  else
    printf("\nThere is no Loop in th List.\n");
}
