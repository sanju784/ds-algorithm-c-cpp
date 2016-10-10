#include <stdio.h>

int A[10] = {};
int N, K;

void print(int *a) {
	int i;
	for(i = 0;i < N; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
}

void k_string(int n, int k) {
	if(n<1) {
		print(A);
	} else {
		int i;
		for(i = 0; i < k; i++) {
			A[n-1] = i;
			k_string(n-1,k);
		}
	}
}

void main() {
	N = 3, K = 3;
	k_string(N, K);
}