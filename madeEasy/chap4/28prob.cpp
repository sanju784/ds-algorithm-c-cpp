#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printStack(stack<char> s) {
	if(s.empty())
		return;
	char c = s.top();
	s.pop();
	printStack(s);
	cout<<c;
}

int main() {
	string str;
	cout<<"\nEnter string : ";
	cin>>str;
	stack<char> s;
	for(int i = 0; i < str.length(); i++) {
		if(s.empty() || s.top() != str[i]) {
			s.push(str[i]);
		} else if(s.top() == str[i]) {
			s.pop();
		}
	}
	cout<<"\nResult : ";
	printStack(s);
	return 0;
}