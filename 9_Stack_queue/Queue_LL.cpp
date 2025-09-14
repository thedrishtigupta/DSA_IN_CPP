#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() : data(0), next(NULL)
    { }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    Node (int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

class Queue {
    public:
    Node* head, *tail;
    int sz;
    Queue() {
        head = tail = NULL;
        sz = 0;
    }

    void push(int d) {
        if (!head) {
            head = tail = new Node(d);
        } else {
            Node* n = new Node(d);
            tail->next = n;
            tail = n;
        }
        sz++;
    }

    void pop() {
        if (!head) return;
        else if (!head->next) {delete head; head = tail = NULL;}
        else {
            Node* t = head;
            head = head->next;
            delete t;
        }
        sz--;
    }

    int front() {
        return head->data;
    }

    bool empty() {
        return head==NULL;
    }

    int size() {return sz;}
};
int main() {
    Queue q;
    for (int i = 0; i < 5; i++) q.push(i);
    cout<<q.size()<<endl;

    while (!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}