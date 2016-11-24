#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

stack<int> valStk;
stack<char> oprStk;

int isNumber(char ch) {
	return (ch >= '0' && ch <= '9');
}

int getPrecedence(char ch) {
	switch (ch) {
		case '+':
		case '-':
		return 1;
		break;
		case '*':
		case '/':
		return 2;
		break;
		case '^':
		return 3;
		break;
	}
	return -1;
}

int evaluate(int val1, int val2, char op) {
	switch (op) {
		case '+': return (val1 + val2);
		case '-': return (val1 - val2);
		case '*': return (val1 * val2);
		case '/': return (val1 / val2);
		case '^': return pow(val1, val2);
	}
}

int main() {
	string exp;
	cout<<"\nEnter the numerical expression :";
	cin>>exp;
	for (int i = 0;i < exp.size(); i++) {
		if(isNumber(exp[i])) {
			valStk.push(exp[i] - '0');
		} else if(oprStk.empty() || exp[i] == '(') {
			oprStk.push(exp[i]);
		} else if(exp[i] == ')') {
			while (oprStk.top() != '(') {
				char op = oprStk.top();
				oprStk.pop();
				int val2 = valStk.top();
				valStk.pop();
				int val1 = valStk.top();
				valStk.pop();
				int res = evaluate(val1, val2, op);
				valStk.push(res);
			}
			oprStk.pop();
		} else if (getPrecedence(exp[i]) >= getPrecedence(oprStk.top())) {
          oprStk.push(exp[i]);
		} else {
			while(getPrecedence(oprStk.top()) > getPrecedence(exp[i]) && !oprStk.empty()) {
				char op = oprStk.top();
				oprStk.pop();
				int val2 = valStk.top();
				valStk.pop();
				int val1 = valStk.top();
				valStk.pop();
				int res = evaluate(val1, val2, op);
				valStk.push(res);
			}
			oprStk.push(exp[i]);
		}
	}
	while(!oprStk.empty()) {
		char op = oprStk.top();
		oprStk.pop();
		int val2 = valStk.top();
		valStk.pop();
		int val1 = valStk.top();
		valStk.pop();
		int res = evaluate(val1, val2, op);
		valStk.push(res);
	}
	if(valStk.size() == 1) {
	  cout<<"\nResult "<<valStk.top();
	} else {
	  cout<<"The Mathematical expression is not correct";
	}
	return 0;
}
