#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodes{
  int data;
  struct nodes *next;
}node;

void addNode (node **h, int n) {
  node *newNode = (node*)malloc(sizeof(node));
  newNode->data = n;
  newNode->next = *h;
  *h = newNode;
}
/**
 * The logic behind this program is that at every node we distort the next pointer and make it point to itself
 * So when traversing the List we find any node pointing to itself then we conclude that there exits a loop in List
 * As not to leave list distorted we save the address of next node in a temporary node
 * and when the recursion ends we reset the List using the address of the temporary node
 */
bool isLoopinList(node *head) {
  node *temp_node;
  bool found_loop;
  if (head == head->next) {
    return true;
  }
  if (head->next == NULL) {
    return false;
  }
  temp_node = head->next;
  head->next = head;

  found_loop = isLoopinList(temp_node);
  head->next = temp_node;
  return found_loop;
}

void main() {
 node *head = NULL;
 addNode(&head, 5);
 addNode(&head, 15);
 addNode(&head, 25);
 addNode(&head, 35);
 addNode(&head, 45);

 //to create loop in Link list
 node *temp = head;
 while (temp->next != NULL){
    temp = temp->next;
 }
 temp->next = head->next;

 if(isLoopinList(head)) {
    printf("\nThere is a loop in Link List.\n");
 } else {
   printf("\nNo loop in Link List.");
 }
}
