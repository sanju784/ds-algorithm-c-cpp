#include<iostream>
#include<queue>

using namespace std;

queue <int> q;
queue <int> q1;
queue <int> q2;

int main() {
  for(int i = 11;i <= 20;i++) {
    q.push(i);
  }
  int n = q.size();
  for(int i = 0;i < n;i++) {
    if(i < n/2) {
      q1.push(q.front());
      q.pop();
    } else {
      q2.push(q.front());
      q.pop();
    }
  }
  while(!q2.empty()) {
    q.push(q1.front());
    q1.pop();
    q.push(q2.front());
    q2.pop();
  }
  return 0;
}
