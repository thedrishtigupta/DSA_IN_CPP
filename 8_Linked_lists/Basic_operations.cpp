#include <iostream>
#include <algorithm>
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

    void deleteFront() {
        if (head == NULL) return;
        else if (head->next == NULL) {delete head; head = tail = NULL;}
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteBack() {
        if (head == NULL) return;
        else if (head->next == NULL) {delete head; head = tail = NULL;}
        else {
            Node* temp = head;
            // while((temp->next)->next != NULL) temp = temp->next; // does work, but we have access to tail
            while (temp->next != tail) temp = temp->next;
            delete tail;
            tail= temp;
            temp->next = NULL;
        }
    }

    void deletePos(int pos) {
        if (pos == 0) {deleteFront(); return;}
        if (pos >= lengthLL()-1) {deleteBack(); return;}

        Node* temp = head;
        for (int i = 0; i < pos-1; i++) temp = temp->next;
        
        Node* n = temp->next;
        temp->next = n->next;
        delete n;
    }

    void reverseLL() {
        Node* c = head;
        Node* p = NULL;
        Node* n;

        while (c != NULL) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        swap(head, tail);
    }

    Node* searchLL(int key) { //returning address, as there is no indexing
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) return temp;

            temp = temp->next;
        }
        return NULL; // either gives segmentation fault or 0
    }
    Node* searchRec(Node* h, int key) {
        if (h == NULL) return NULL;

        if (h->data == key) return h;

        return searchRec(h->next, key);
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

    L1.printLL();
    // cout<<L1.searchLL(15);

    Node* ans = L1.searchRec(L1.head, 15);
    if (ans) cout<<"Key found"<<endl;
    else cout<<"Key not found"<<endl;
    return 0;
}