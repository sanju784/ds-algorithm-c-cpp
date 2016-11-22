#include <iostream>
#include <stack>
#include <string>

using namespace std;

int isPalindrome(string c) {
  stack<char> s;
  int i=0;
  while (c[i] != 'X') {
    s.push(c[i]);
    i++;
  }
  i++;
  while(c[i] && !s.empty()) {
    if(c[i] != s.top()) {
        return 0;
    }
    s.pop();
    i++;
  }
  if(i == c.size() && s.empty())
    return 1;
  else
    return 0;
}

int main() {
  string str;
  cout<<"Enter the string ";
  cin>>str;
  if(isPalindrome(str)) {
    cout<<"\nIs Palindrome";
  } else {
    cout<<"\nIs not Palindrome";
  }
  return 0;
}
