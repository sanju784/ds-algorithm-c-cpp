#include <iostream>
#include <stack>

using namespace std;


/**
 * Take a global Stack.
 * All changes will be reflected to it.
 */
stack<int> s;

void insertAtBottom(int item) {
  if(s.empty()) {
    s.push(item);
  } else {
    int temp = s.top();
    s.pop();
    insertAtBottom(item);
    s.push(temp);
  }
}

void reverseStack() {
    if(!s.empty()) {
    int temp = s.top();
    s.pop();
    reverseStack();
    insertAtBottom(temp);
  }
}

void printStack(stack<int> s) {
  while(!s.empty()) {
    cout<<s.top()<<endl;
    s.pop();
  }
}

int main() {
  for(int i=1;i<=5;i++) {
    s.push(i);
  }
  cout<<"Current Stack"<<endl;
  printStack(s);
  reverseStack();
  cout<<"Stack after reverse"<<endl;
  printStack(s);
  return 0;
}
