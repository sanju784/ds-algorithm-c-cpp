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

void printnFromLast(node *head, int n) {
  static int i = 0;
  if(head == NULL) {
  	printf("\nThe required node does not exist.\n");
  	return;
  }
  printnFromLast(head->next, n);
  if(++i == n) {
  	printf("\nThe nth node is %d \n", head->data);
  }
}

void main () {
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