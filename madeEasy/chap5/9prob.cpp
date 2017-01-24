#include<iostream>
#include<math.h>
#include<stack>
#include<queue>

using namespace std;

stack <int> s;
queue <int> q;

int checkSuccessivePair() {
  int i = 0;
  while(!s.empty()) {
    int n = s.top();
    s.pop();
    q.push(n);
    i++;
  }
  if(i%2){
    q.pop();
  }
  while(!q.empty()) {
    int n1 = q.front();
    q.pop();
    int n2 = q.front();
    q.pop();
    if(abs(n1-n2) == 1) {
        continue;
    } else {
      return 0;
    }
  }
  return 1;
}

int main() {
  s.push(4);
  s.push(5);
  s.push(-2);
  s.push(-3);
  s.push(11);
  s.push(10);
  s.push(5);
  s.push(6);
  s.push(20);
  if(checkSuccessivePair()) {
    printf("\nThe stack has successive pair.\n");
  } else {
    printf("\nThe stack do not have successive pair.\n");
  }
  return 0;
}
