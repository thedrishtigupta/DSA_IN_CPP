#include <iostream>
#include<vector>
using namespace std;

class Queue {
    public :
    vector<int> v;

    void push(int data) {
        v.push_back(data);
    }

    void pop() {
        v.erase(v.begin());
    }

    int front() {
        return v[0];
    }

    bool empty() {
        return v.size() == 0;
    }
};

int main() {
    Queue q;
    for (int i = 0; i < 5; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}