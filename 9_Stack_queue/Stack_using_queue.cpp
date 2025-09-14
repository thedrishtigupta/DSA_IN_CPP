#include <iostream>
#include <queue>
using namespace std;

class Stack {
    public:
    queue<int> q1, q2;

    void push(int d) {
        if (!q2.empty()) q2.push(d);
        else q1.push(d);
    }

    void pop() {
        if (!q1.empty() && q2.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        } else if (!q2.empty() && q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
    }

    int top() {
        if (!q1.empty() && q2.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int ans = q1.front();
            q1.pop();
            q2.push(ans);
            return ans;
        } else if (!q2.empty() && q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int ans = q2.front();
            q2.pop();
            q1.push(ans);
            return ans;
        }
        return -1;
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};
int main() {
    Stack s;
    
    for (int i = 1; i < 5; i++) s.push(i);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}