#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

void printDisk(int n, char f, char t) {
  cout<<"Moving disk "<<n<<" from "<<f<<" to "<<t<<endl;
}

void moveDisk(stack<int> &src, stack<int> &dest, char s, char d) {
	if(src.empty()) {
		printDisk(dest.top(), d, s);
		src.push(dest.top());
		dest.pop();
	} else if(dest.empty()) {
		printDisk(src.top(), s, d);
		dest.push(src.top());
		src.pop();
	} else if(src.top() > dest.top()) {
		printDisk(dest.top(), d, s);
		src.push(dest.top());
		dest.pop();
	} else if(dest.top() > src.top()) {
		printDisk(src.top(), s, d);
		dest.push(src.top());
		src.pop();
	}
}

int main() {
	stack<int> src, dest, aux;
	unsigned n;
	int i, no_of_moves;
	char s = 'S', d = 'D', a = 'A';
	cout<<"Enter number of disks ";
	cin>>n;
	no_of_moves = pow(2,n) - 1;
	for(i = n; i >=1; i--) {
		src.push(i);
	}
	if(n%2 == 0) {
		char t;
		t = d;
		d = a;
		a = t;
	}

	for(i = 1;i <= no_of_moves; i++) {
		if(i%3 == 1) {
			moveDisk(src, dest, s, d);
		} else if(i%3 == 2) {
			moveDisk(src, aux, s, a);
		} else if(i%3 == 0) {
			moveDisk(aux, dest, a, d);
		}
	}
	return 0;
}