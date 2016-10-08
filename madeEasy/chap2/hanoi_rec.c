#include <stdio.h>

void hanoi(int, char, char, char);
void main() {
	int n;
	printf("Enter the number of disks: ");
	scanf("%d", &n);
	char source = 'A', auxilary = 'B', destination = 'C';
	hanoi(n, source, destination, auxilary);
}

void hanoi(int n, char source, char destination, char auxilary) {
	if (n == 1) {
		printf("\nMoving disk 1 from %c to %c\n", source, destination);
		return;
	}

	hanoi(n-1, source, auxilary, destination);
	printf("\nMoving disk %d from %c to %c\n", n, source, destination);
	hanoi(n-1, auxilary, destination, source);
}