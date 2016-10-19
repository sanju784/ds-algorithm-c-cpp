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

/**
 * If loop is detected then run through the loop with both pointer with same pace
 * i.e. slow run one and fast run two at a time then they will always meet at the same point in the loop
 * we use this logic to find length of the loop
 */
int getLoopLength(node *h) {
	node *slowPtr = h;
	node *fastPtr = h;
	int i = 0;
	while(fastPtr && fastPtr->next) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr == fastPtr) {
          slowPtr = slowPtr->next;
		  fastPtr = fastPtr->next->next;
		  i++;
          break;
        }
    }
    while (slowPtr != fastPtr && fastPtr->next) {
        i++;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
  return i;
}

/**
 * First find the starting point of the loop and mark that node then
 * 1. count the nodes in the loop
 * 2. nodes from head to start point of loop
 * Then add these two result to get the total length of the list with cycles.
 */
int getListLength(node *h) {
  node *slowPtr, *fastPtr;
  slowPtr = fastPtr = h;
  int count = 0;
  while (fastPtr && fastPtr->next) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if (fastPtr == slowPtr)
        break;
  }
  slowPtr = h;
  if(fastPtr == NULL || fastPtr->next == NULL) {
    while(slowPtr) {
      count++;
      slowPtr = slowPtr->next;
    }
  }
  while(slowPtr != fastPtr && fastPtr->next && fastPtr) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next;
    count++;
  }
  if (fastPtr && fastPtr->next) {
    fastPtr = fastPtr->next;
    count++;
  }
  while(slowPtr != fastPtr && fastPtr->next && fastPtr) {
    fastPtr = fastPtr->next;
    count++;
  }
  return count;
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
  printf("\nThe loop length is %d\n", getLoopLength(head));
  printf("\nThe total length of list is %d\n", getListLength(head));
}
