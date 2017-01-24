#include<iostream>
#include<deque>

using namespace std;

int main() {
  int arr[] = {1,3,-1,-3,5,3,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  int i, w = 3;
  deque<int> dq(w);
  for (i = 0;i < w;i++) {
    while(!dq.empty() && arr[i] >= arr[dq.back()]) {
        dq.pop_back();
    }
    dq.push_back(i);
  }
  for(;i < n;i++) {
    cout<<arr[dq.front()]<<" ";
    while(!dq.empty() && dq.front() <= i - w)
        dq.pop_front();
    while(!dq.empty() && arr[i] >= arr[dq.back()])
        dq.pop_back();
    dq.push_back(i);
  }
  cout<<arr[dq.front()];
  return 0;
}
