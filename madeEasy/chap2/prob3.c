#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[10] = {0};
// void init (int n) {
// 	a = (char*)malloc(n*sizeof(char));
// }
void binary(int);

void main() {
	int n;
	printf("Enter the no of bits you want ");
	scanf("%d", &n);
	printf("\n");
	//init(n);
	binary(n);
}

void binary (int n) {
	if(n<1) {
		printf("%s\n", a);
	} else {
		a[n-1] = '0';
		binary(n-1);
		a[n-1] = '1';
		binary(n-1);
	}
}