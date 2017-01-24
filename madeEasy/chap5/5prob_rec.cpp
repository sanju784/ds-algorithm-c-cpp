#include<iostream>
#include<stack>
#include<queue>

using namespace std;

queue <int> q;
stack <int> s;

void enterStack() {
  if(q.size() == 0)
    return;
  int n = q.front();
  q.pop();
  enterStack();
  s.push(n);
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
