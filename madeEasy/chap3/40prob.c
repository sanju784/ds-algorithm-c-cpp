#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} node;

void display(node *h) {
  node *temp = h;
  do {
    printf("-->%d", temp->data);
    temp = temp->next;
  } while(temp != h);
}

int getJosephusPos(node *h, int n, int m) {
  node *first, *last;
  int i, count;
  first = last = (node*)malloc(sizeof(node));
  first->data = 1;
  for(i = 2; i <= n; i++) {
    last->next = (node*)malloc(sizeof(node));
    last = last->next;
    last->data = i;
  }
  last->next = first;
  for (count = n; count > 1; count--) {
    for(i = 0; i < (m-1); i++) {
      last = last->next;
    }
    last->next = last->next->next;
  }
  return last->data;
}

void main() {
  node *head = NULL;
  int n, m;
  printf("\nEnter the number of people. ");
  scanf("%d", &n);
  printf("\n\nEnter value of m. ");
  scanf("%d", &m);
  printf("\nThe Josephus Position is %d\n", getJosephusPos(head, n, m));
}

