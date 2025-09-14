#include <iostream>
#include<queue>
using namespace std;
void reverseQueue(queue<int>& q) {
    if (q.empty()) return;

    int fr = q.front();
    q.pop();
    reverseQueue(q);
    q.push(fr);
}
int main() {
    queue<int> q;
    for (int i = 1; i < 5; i++) q.push(i);

    reverseQueue(q);

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}