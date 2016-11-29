#include <stdio.h>

void stackGrowth(int*);

void testStackGrowth1() {
	int temp;
	stackGrowth(&temp);
}

void stackGrowth(int *temp) {
	int temp2;
	printf("\nAddress of first local variable is %u", temp);
	printf("\nAdress of second local variable is %u", &temp2);
	if(temp < &temp2)
		printf("\nStack is growing upwards.");
	else
		printf("\nStack is growing downwards.");
}

void main() {
	testStackGrowth1();
}