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

    void push_front(int data) {
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

    void push_back(int data) {
        if (head == NULL) {
            head = tail = new Node(data);
            return;
        }
        Node* n = new Node(data);
        tail->next = n;
        tail = n;
    }

    void push(int pos, int data) {
        if (pos == 0) {
            push_front(data);
            return;
        } else if (pos >= lengthLL()) {
            push_back(data);
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

    void pop_front() {
        if (head == NULL) return;
        else if (head->next == NULL) {delete head; head = tail = NULL;}
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pop_back() {
        if (head == NULL) return;
        else if (head->next == NULL) {delete head; head = tail = NULL;}
        else {
            Node* temp = head;
            while (temp->next != tail) temp = temp->next;
            delete tail;
            tail= temp;
            temp->next = NULL;
        }
    }

    void pop(int pos) {
        if (pos == 0) {pop_front(); return;}
        if (pos >= lengthLL()-1) {pop_back(); return;}

        Node* temp = head;
        for (int i = 0; i < pos-1; i++) temp = temp->next;
        
        Node* n = temp->next;
        temp->next = n->next;
        delete n;
    }

};