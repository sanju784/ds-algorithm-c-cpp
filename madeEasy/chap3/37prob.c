#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void reverseList(node **h) {
  node *prev = NULL;
  node *current = *h;
  node *next;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *h = prev;
}

bool compareList(node *h1, node *h2) {
  while (h1 != NULL) {
    if(h1->data != h2->data) {
      return false;
    }
    h1 = h1->next;
    h2 = h2->next;
  }
  return true;
}

bool isPalindrome(node *h) {
  node *fastPtr = h;
  node *slowPtr = h;
  node *prevMid;
  node *second_half_head;
  bool res;
  while (fastPtr && fastPtr->next) {
    prevMid = slowPtr;
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  second_half_head = slowPtr;
  prevMid->next = NULL;
  reverseList(&second_half_head);
  res = compareList(h, second_half_head);
  reverseList(&second_half_head);
  prevMid->next = second_half_head;
  return res;
}

int main() {
  node *head = NULL;
  addNode(&head, 5);
  addNode(&head, 15);
  addNode(&head, 5);
  addNode(&head, 5);
  addNode(&head, 5);
  addNode(&head, 15);
  addNode(&head, 5);
  display(head);
  printf("\n\n");
  if (head == NULL || head->next == NULL) {
    printf("\nThe list is Palindrome\n");
    return 0;
  }
  if(isPalindrome(head)) {
    printf("\nThe list is Palindrome");
  } else {
    printf("\nThe list is not Palindrome");
  }
  printf("\n\n");
  display(head);
  return 0;
}
