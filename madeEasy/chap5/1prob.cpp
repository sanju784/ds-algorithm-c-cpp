#include <iostream>
#include <queue>

using namespace std;

queue <int> q;

void reverse() {
    if(q.size() == 0)
        return;
    int n = q.front();
    cout<<n<<" is poped"<<endl;
    q.pop();
    reverse();
    q.push(n);
}

int main() {
    q.push(5);
    q.push(3);
    q.push(2);
    reverse();
    return 0;
}
