#include <iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int>& s, int top) {
    if (s.empty()) {s.push(top); return;}

    int x = s.top();
    s.pop();
    insertBottom(s, top);
    s.push(x);
}
void reverse(stack<int>& s) {
    if (s.empty()) return;
    int top = s.top();
    s.pop();
    reverse(s);
    insertBottom(s, top);
}
int main() {

    stack<int> s;

    for (int i = 5; i > 0; i--) s.push(i);

    reverse(s);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}