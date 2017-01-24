#include <iostream>
#include <queue>
#include <deque>

using namespace std;

deque <int> dq;
queue <int> q;

int main() {
  for(int i = 10;i < 100;i += 10) {
    dq.push_back(i);
  }
  int k = 4;
  for(int i = 0;i < k;i++) {
    q.push(dq.front());
    dq.pop_front();
  }
  while(!q.empty()) {
    dq.push_front(q.front());
    q.pop();
  }
  return 0;
}
