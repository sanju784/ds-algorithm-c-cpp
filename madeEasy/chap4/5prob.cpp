#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> s;
	stack<int> min_s;
	int n, n1;
	char ch;
	for(int i=0;i<5;i++) {
		cout<<"\nEnter the elements in stack ";
		cin>>n;
		s.push(n);
		if(min_s.empty() || n <= min_s.top())
			min_s.push(n);
	}
	cout<<"\nThe min in stack is "<<min_s.top();
	cout<<"\nDo you want to remove from stack (Y or N)? ";
	cin>>ch;
	if(ch == 'y' || ch == 'Y') {
		cout<<"\nhow many want to remove? ";
		cin>>n1;
	}
	if(n1>n) cout<<"\nInvalid input.\n";
	else {
		for(int i=0;i<n1;i++) {
			if(s.top() == min_s.top()) {
				min_s.pop();
			}
			s.pop();
		}
	}
	cout<<"\nThe min in stack is "<<min_s.top();
	return 0;
}