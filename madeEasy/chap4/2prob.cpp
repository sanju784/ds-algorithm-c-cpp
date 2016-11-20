#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s;

int isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int getPrecedence(char ch) {
  switch (ch) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
  }
  return -1;
}

//Reverse Polish Notation
char* infixToPostfix(string exp) {
  char *res;
  int j = 0;
  for (int i = 0;i < exp.size();i++) {
    if (isOperand(exp[i])) {
      res[j++] = exp[i];
    } else if (exp[i] == '(' || s.empty()) {
      s.push(exp[i]);
    } else if(exp[i] == ')') {
      while (s.top() != '(') {
        res[j++] = s.top();
        s.pop();
      }
      s.pop();
    } else {
      while (!s.empty() && (getPrecedence(exp[i]) <= getPrecedence(s.top()))) {
        res[j++] = s.top();
        s.pop();
      }
      s.push(exp[i]);
    }
  }
  while(!s.empty()) {
    res[j++] = s.top();
    s.pop();
  }
  return res;
}

int main() {
  string exp;
  cout<<"\nEnter Mathematical Expression : ";
  cin>>exp;
  cout<<"\nThe result is "<<infixToPostfix(exp)<<endl;
  return 0;
}
