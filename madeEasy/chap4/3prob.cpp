#include <iostream>
#include <stack>
#include <string>

using namespace std;

int isOperand(char c) {
	return (c >= '0' && c <= '9');
}

int main() {
	int var1, var2, res;
	stack<int> s;
	string exp;
	cout<<"ENTER the postfix expression : ";
	cin>>exp;
	for(int i = 0;i < exp.size();i++) {
		if(isOperand(exp[i])) {
			s.push(exp[i] - '0');
		} else {
			var2 = s.top();
			s.pop();
			var1 = s.top();
			s.pop();
			switch (exp[i]) {
				case '+': res = var1 + var2; break;
				case '-': res = var1 - var2; break;
				case '*': res = var1 * var2; break;
				case '/': res = var1 / var2; break;
			}
			s.push(res);
		}
	}
	cout<<"\n\nThe result is "<<s.top();
	s.pop();
	return 0;
}