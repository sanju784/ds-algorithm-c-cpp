#include <iostream>
#include <stack>

using namespace std;

int main () {
	int arr[] = {3,2,5,6,1,4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int next, element;
	stack<int> s;
	s.push(arr[0]);
	for(int i = 1;i < n; i++) {
		next = arr[i];
		if(!s.empty()) {
			element = s.top();
			s.pop();
			while(element < next) {
				cout<<element<<" --> "<<next<<endl;
				if(s.empty())
					break;
				element = s.top();
				s.pop();
			}
			if(element > next)
				s.push(element);
		}
		s.push(next);
	}
	while(!s.empty()) {
		element = s.top();
		s.pop();
		cout<<element<<" --> "<<-1<<endl;
	}
	return 0;
}