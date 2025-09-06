#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int d) {
        data = d;
        next = NULL;
    }

};

class LinkedList {
    public:
    Node* head, *tail;
    
    LinkedList() {
        head = tail = NULL;
    }

    void insertAtFront(int data) {
        if (head == NULL) {
            head = tail = new Node(data);
            return;
        }
        Node* t = new Node(data);
        t->next = head;
        head = t;
    }

    void printLL() {
        Node* h = head;
        while (h != NULL) {
            cout<<h->data <<" -> ";
            h = h->next;
        }
        cout<<"NULL"<<endl;
    }

    void insertAtLast(int data) {
        if (head == NULL) {
            head = tail = new Node(data);
            return;
        }
        Node* n = new Node(data);
        tail->next = n;
        tail = n;
    }

    void insertAtPos(int pos, int data) {
        if (pos == 0) {
            insertAtFront(data);
            return;
        } else if (pos >= lengthLL()) {
            insertAtLast(data);
            return;
        }
        Node* t = head;

        for (int i = 0; i < pos-1; i++) t = t->next;

        Node* n = new Node(data);
        n->next = t->next;
        t->next = n;
    }

    int lengthLL() {
        int count = 0;
        Node* t = head;
        while(t != NULL) {
            count++;
            t = t->next;
        }
        return count;
    }
};

// void printLL(Node* h) {
//     while (h != NULL) {
//         cout<<h->data <<" -> ";
//         h = h->next;
//     }
//     cout<<"NULL";
// }

// void insertAtFront(Node* &h, Node* &t, int data) {
//     if (h == NULL) {
//         h = t = new Node(data);
//         return;
//     }

//     Node* t = new Node(data);
//     t->next = h;
//     h = t;
    
// }

int main() {
    LinkedList L1;

    L1.insertAtFront(1);
    L1.insertAtFront(2);
    L1.insertAtFront(3);

    L1.insertAtPos(2, 10);
    L1.insertAtLast(20);

    L1.printLL();
    cout<<L1.lengthLL();
    return 0;
}