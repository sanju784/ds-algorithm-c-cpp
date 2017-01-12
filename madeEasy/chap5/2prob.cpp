#include <iostream>
#include <stack>
#include <climits>

using namespace std;

stack <int> stk1, stk2;

void push(int n) {
  stk1.push(n);
}

int pop() {
  if(stk1.empty()) {
    cout<<"Queue is empty"<<endl;
    return INT_MIN;
  }
  while (!stk1.empty()) {
    int n = stk1.top();
    stk1.pop();
    stk2.push(n);
  }
  int n = stk2.top();
  stk2.pop();
  while (!stk2.empty()) {
    int n = stk2.top();
    stk2.pop();
    stk1.push(n);
  }
  return n;
}

int main() {
  push(5);
  push(3);
  push(2);
  cout<<pop()<<endl;
  cout<<pop()<<endl;
  push(1);
  cout<<pop()<<endl;
  cout<<pop()<<endl;
  return 0;
}
