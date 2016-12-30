#include <stdio.h>
#include <limits.h>
#define MAX 6

int stk[MAX];
int top1 = -1, top2 = -1, top3 = -1;
int base3 = MAX/3;

void pushStk3Up() {
	int i;
	if(top3 == -1) {
		base3++;
	} else {
	  for (i = top3; i >= base3 ; i--) {
		stk[i+1] = stk[i];
	  }
	  base3++;
	  top3++;
  }
}

void pushStk3Down() {
	int i;
	if(top3 == -1) {
		base3--;
	} else {
	  for (i = base3; i <= top3 ; i++) {
		stk[i-1] = stk[i];
	  }
	  base3--;
	  top3--;
  }
}

int isFull() {
  if(top1 == (base3 - 1) && top3 == (top2 - 1))
  	return 1;
  else if(top1 == (top2 - 1))
  	return 1;
  else if(top1 == (MAX - 1) || top2 == 0)
  	return 1;
  else if(base3 == 0 && top3 == (MAX - 1))
  	return 1;
  else
  	return 0;
}

int isEmpty() {
  if(top1 == -1 && top2 == -1 && top3 == -1)
  	return 1;
  else
  	return 0;
}

void push1 (int n) {
  if(isFull()) {
  	printf("\nStack Overflow.\n");
  } else if(top1 == base3 - 1) {
  	pushStk3Up();
  	stk[++top1] = n;
  } else {
  	stk[++top1] = n;
  }
}

void push2 (int n) {
  if(isFull()) {
  	printf("\nStack Overflow.\n");
  } else {
  	if(top3 == (top2 - 1) || top3 == (MAX - 1)) {
  		pushStk3Down();
  		if (top2 == -1) {
  			stk[MAX - 1] = n;
  			top2 = MAX - 1;
  		} else {
  	      stk[--top2] = n;
  	    }
  	} else if(top2 == -1) {
  		stk[MAX - 1] = n;
  		top2 = MAX - 1;
  	} else {
  		stk[--top2] = n;
  	}
  }
}

void push3 (int n) {
  if(isFull()) {
  	printf("\nStack Overflow.\n");
  } else {
  	if (top3 == -1) {
  		top3 = base3;
  		stk[top3] = n;
  	} else if(top3 == top2 - 1) {
  		pushStk3Down();
  		stk[++top3] = n;
  	} else if(base3 == INT_MIN) {
        base3 = top1 + 1;
  		top3 = base3;
  		stk[top3] = n;
  	} else {
  		stk[++top3] = n;
  	}
  }
}

int pop1() {
  if(top1 == -1)
  	return INT_MIN;
  else 
  	return stk[top1--];
}

int pop2() {
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

int pop3() {
	if(top3 == -1)
		return INT_MIN;
	else {
		int val= stk[top3];
		if(top3 == base3) {
			top3 = -1;
			base3 = INT_MIN;
		} else {
		  top3--;
		}
	  return val;
	}
}

void main() {
	char ch = 'Y';
	int st, n, op;
	do{
		printf("\nStack you want to operate? (1, 2 or 3) ");
		scanf("%d", &st);
		printf("\nDo you want to push(1) or pop(2)? (1 or 2) ");
		scanf("%d", &op);
		switch (op) {
			case 1:
			  printf("\nEnter no u want to push ");
			  scanf("%d", &n);
			  if(st == 1) {
			  	push1(n);
			  } else if(st == 2) {
			  	push2(n);
			  } else if(st == 3) {
			  	push3(n);
			  } else {
			  	printf("\nThe stack do not exist.\n");
			  }
			break;
			case 2:
			if(st == 1) {
			  	n = pop1();
			  } else if(st == 2) {
			  	n = pop2();
			  } else if(st == 3) {
			  	n = pop3();
			  } else {
			  	printf("\nThe stack do not exist.\n");
			  }
			  if(n == INT_MIN)
			  	printf("\n%d Stack is empty", st);
			  else
			    printf("\n\n%d is popped from stack%d", n, st);
			break;
		}
		printf("\nDo you want to continue? (Y or N) :");
		ch = getche();
	} while (ch != 'n' || ch != 'N');
}