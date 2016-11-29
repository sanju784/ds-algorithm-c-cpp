#include <stdio.h>

void main() {
	int a[5] = {6,3,4,5,2};
	int span[5], i;
	for(i = 0;i < 5; i++) {
		int j = 1;
		while(j <= i && a[i] > a[i-j]) {
			j++;
		}
		span[i] = j;
	}

	for (i = 0; i < 5;i++)
		printf("%d  ", span[i]);
}