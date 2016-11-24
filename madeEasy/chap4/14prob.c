#include <stdio.h>
#include <conio.h>
#include <limits.h>
#define MAX 5

int stk[MAX];
int top1 = -1;
int top2 = -1;

void push1(int n) {
    if(top1 == (MAX - 1) || top2 == (MAX - 1) || (top1 + 1) == top2) {
        printf("\nStack Overflow.");
        return;
    }
    stk[++top1] = n;
}

int pop1(){
    int val;
    if(top1 == -1)
        return INT_MIN;
    else{
        val = stk[top1];
        top1--;
        return val;
    }
}

void push2(int n) {
    if(top1 == (MAX - 1) || top2 == (MAX - 1) || (top1 + 1) == top2) {
        printf("\nStack Overflow.");
        return;
    }
    if(top2 == -1){
        top2 = MAX;
    }
    stk[--top2] = n;
}

int pop2(){
    if(top2 == -1)
        return INT_MIN;
    else {
        int val = stk[top2];
        top2++;
        if(top2 == MAX)
            top2 = -1;
        return val;
    }
}

void main(){
    int opt, n, st, p;
    char ch = 'Y';
    do {
      printf("\n-------------------");
      printf("\nEnter stack in which you want to Operate (1 or 2)? :");
      scanf("%d", &st);
      printf("\nDo you want to Push(0) or Pop(1)? :");
      scanf("%d", &opt);
      switch (opt) {
          case 0:
            printf("\nEnter number want to insert? :");
            scanf("%d", &n);
            if(st == 1) {
              push1(n);
            } else if (st == 2) {
              push2(n);
            }
            break;
          case 1:
            if(st == 1) {
              p = pop1();
            } else if (st == 2) {
              p = pop2();
            }
            if(p == INT_MIN)
                printf("\nStack is empty.");
            else
                printf("%d is popped out of Stack%d", p, st);
      }
      printf("\nDo you want to continue? (Y or N) :");
      ch = getche();
    } while (ch == 'Y' || ch == 'y');
}
