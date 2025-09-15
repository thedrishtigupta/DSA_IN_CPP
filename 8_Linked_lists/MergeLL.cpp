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

    void bubbleSortLL() {
    int len = lengthLL();

    for (int i = 0; i < len-1; i++) {
        Node* c = head;
        Node* p = NULL, *n;
        while (c!= NULL && c->next != NULL) {
            n = c->next;
            if (c->data > n->data) { // swapping
                c->next = n->next;
                n->next = c;
                if (p == NULL) { // head change
                    head = p = n;

                } else { // no head change
                    p->next = n;
                    p = n;
                }

            } else { // no swapping
                p = c;
                c = n;
            }
        }
    }
}
};


void breakCycle (Node* head, Node* fast) {
    Node* s = head;
    node* pf = head;

    while (pf->next != f) pf = pf->next;

    while (f != s) {
        pf = f;
        f = f->next;
        s = s->next;
    }
    pf->next = NULL;
}

int loopLen(Node* head) {
    if (!head || !head->next) return 0;
    Node* s = head, *f = head;
    int len = 0;

    while (f && f->next) {
        s = s->next;
        f = f->next->next;
        len++;
        if (s == f) break;
    }

    if (!f || !f->next) return 0;

    return len;
}

void printLL(Node* &head) {
        Node* h = head;
        while (h != NULL) {
            cout<<h->data <<" -> ";
            h = h->next;
        }
        cout<<"NULL"<<endl;
    }

Node* mergeLL(Node* &a, Node* &b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (a->data < b->data) {
        Node* c = a;
        c->next = mergeLL(a->next, b);
        return c;
    } else {
        Node* c = b;
        c->next = mergeLL(a, b->next);
        return c;
    }
}

// Node* mergeSort(Node* head) {
//     if (head == NULL || head->next == NULL) return head;

//     Node* m = midLL(head);
//     Node* a = head;
//     Node* b = m->next;
//     m->next = NULL;

//     a = mergeSort(a);
//     b = mergeSort(b);

//     Node* c = mergeLL(a, b);
//     return c;
// }



int main() {
    LinkedList L1, L2, L3;

    L1.insertAtLast(1);
    L1.insertAtLast(3);
    L1.insertAtLast(5);
    L2.insertAtLast(2);
    L2.insertAtLast(4);
    L2.insertAtLast(6);
    L2.insertAtLast(7);

    // L1.printLL();
    // L2.printLL();

    L3.insertAtLast(5);
    L3.insertAtLast(3);
    L3.insertAtLast(1);
    L3.insertAtLast(2);

    L3.printLL();

    L3.bubbleSortLL();

    L3.printLL();


    return 0;
}