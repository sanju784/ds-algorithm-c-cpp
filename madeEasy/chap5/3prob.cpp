#include<iostream>
#include<queue>
#include<climits>

using namespace std;

queue <int> q1;
queue <int> q2;

void push_stk(int n) {
  q1.push(n);
}

int pop_stk() {
  //don't use q1.size in for loop as size of q1 will change with the use of push or pop
  int s1 = q1.size();
  if(s1 == 0) {
    cout<<"Stack underflow"<<endl;
    return INT_MIN;
  }
  for(int i = 0;i < (s1 - 1); i++) {
    int n = q1.front();
    q1.pop();
    q2.push(n);
  }
  int n = q1.front();
  q1.pop();
  while(!q2.empty()) {
    int n = q2.front();
    q2.pop();
    q1.push(n);
  }
  return n;
}

int main() {
  push_stk(5);
  push_stk(3);
  push_stk(2);
  cout<<pop_stk()<<endl;
  cout<<pop_stk()<<endl;
  push_stk(1);
  cout<<pop_stk()<<endl;
  cout<<pop_stk()<<endl;
  return 0;
}
