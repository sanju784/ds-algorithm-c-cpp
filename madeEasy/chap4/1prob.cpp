#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> s;

int isMatchingPair(char a, char b) {
  if (a == '(' && b == ')') return 1;
  if (a == '[' && b == ']') return 1;
  if (a == '{' && b == '}') return 1;
  return 0;
}
int main() {
  string exp;
  cout<<"\nEnter the mathematical Expression ";
  cin>>exp;
  for(int i = 0;i < exp.size(); i++) {
    if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
        s.push(exp[i]);
    }
    if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
        if(!s.empty() && isMatchingPair(s.top(), exp[i])) {
            s.pop();
        } else {
          cout <<"\nThe mathematical expression is not correct";
          exit(0);
        }
    }
  }
  if(s.empty()) {
    cout<<"\nThe expression is correct\n";
  } else {
    cout <<"\nThe mathematical expression is incorrect";
  }
  return 0;
}
