#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main () {
	int arr[] = {6,3,4,5,2};
	int span[5];
	st.push(0);
	span[0] = 1;
	for(int i = 1;i < 5;i++) {
		while(!st.empty() && arr[st.top()] <= arr[i])
			st.pop();
		span[i] = (st.empty()) ? (i + 1) : (i-st.top());
		st.push(i);
	}
	for(int i = 0; i < 5; i++)
		cout<<span[i]<<"  ";
	return 0;
}