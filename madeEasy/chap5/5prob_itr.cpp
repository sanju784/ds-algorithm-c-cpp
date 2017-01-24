#include<iostream>
#include<stack>
#include<queue>

using namespace std;

queue <int> q;
stack <int> s;

void enterStack() {
  while(!q.empty()) {
    int n = q.front();
    q.pop();
    s.push(n);
  }
  while(!s.empty()) {
    int n = s.top();
    s.pop();
    q.push(n);
  }
  while(!q.empty()) {
    int n = q.front();
    q.pop();
    s.push(n);
  }
}

//This is to check that the recursion function worked properly
//To check it do un-comment the function below and run
/*
void printStk() {
  while(!s.empty()) {
    cout<<s.top()<<endl;
    s.pop();
  }
}
*/

int main() {
  q.push(5);
  q.push(3);
  q.push(3);
  q.push(1);
  enterStack();
  //printStk();
  return 0;
}
