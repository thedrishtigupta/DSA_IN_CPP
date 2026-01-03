#include <iostream>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;


class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node() : data(0), left(NULL), right(NULL)
    { }

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    Node (int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Pair{
    public:
    int height;
    bool isBal;
};

class LinkedList {
    public:
    Node* head;
    Node* tail;
};

Node* insertBST(Node* root, int d) {
    if(!root) {
        return new Node(d);
    }

    if (root->data > d) root->left = insertBST(root->left, d);
    else root->right = insertBST(root->right, d);

    return root;
}

Node* buildBST() {
    int d;
    cin>>d;

    Node* root = NULL;
    while(d != -1) {
        root = insertBST(root, d);
        cin>>d;
    }
    return root;
}

void PreOrder(Node* root) {
    if(!root) return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node* root) {
    if(!root) return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PostOrder(Node* root) {
    if(!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

void LevelOrder(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* x = q.front();
        q.pop();
        if (x) {
            cout<<x->data<<" ";
            if (x->left) q.push(x->left);
            if (x->right) q.push(x->right);
        } else {
            cout<<'\n';
            if (!q.empty()) q.push(NULL);
        }
    }
}

void printRange(Node* root, int s, int e) { //Preorder format
    if (!root) return;
    if (root->data >= s and root->data <= e) {
        cout<<root->data <<" ";
    }
    printRange(root->left, s, e);
    printRange(root->right, s, e);
}


Node* searchBST(Node* root, int tar) {
    if (!root) return NULL;
    
    if(root->data == tar) return root;
    else if (root->data > tar) return searchBST(root->left, tar);
    else return searchBST(root->right, tar);
}

bool isBST(Node* root, int min = INT_MIN, int max = INT_MAX) {
    if (!root) return true;

    return (root->data >= min && root->data <= max && isBST(root->left) && isBST(root->right));
}

Pair isBalanced(Node* root) {
    Pair p;
    if (!root) {
        p.height = 0;
        p.isBal = true;
        return p;
    }
1
    Pair left = isBalanced(root->left);
    Pair right = isBalanced(root->right);

    p.height = max(left.height, right.height) +1;

    p.isBal = (abs(left.height - right.height) <= 1) and left.isBal and right.isBal;

    return p;
}

LinkedList BSTtoLL(Node* root) {
    LinkedList l;
    if(!root) {
        l.head = l.tail = NULL;
        return l;
    }

    if(root->left and root->right) {
        LinkedList left = BSTtoLL(root->left);
        LinkedList right = BSTtoLL(root->right);

        left.tail->right = root;
        root->left = NULL;
        root->right = right.head;

        l.head = left.head;
        l.tail = right.tail;

        return l;
    } else if (root->left and !root->right) {
        LinkedList left = BSTtoLL(root->left);
        left.tail->right = root;
        root->left = NULL;

        l.head = left.head;
        l.tail = root;
        return l;
    } else if (!root->left and root->right) {
        LinkedList right = BSTtoLL(root->right);
        root->left = NULL;
        root->right = right.head;

        l.head = root;
        l.tail = right.tail;
        return l;
    } else {
        root->left = NULL;
        root->right = NULL;
        l.head = l.tail = root;
        return l;
    }
}

void printLL(Node* h) {
    while (h != NULL) {
        cout<<h->data <<" -> ";
        h = h->right;
    }
    cout<<"NULL"<<endl;
}

Node* ARRtoBST(int* arr, int s, int e) {
    if (s > e) return NULL;

    int mid = s + ((e-s)/2);
    Node* root = new Node(arr[mid]);
    root->left = ARRtoBST(arr, s, mid-1);
    root->right = ARRtoBST(arr, mid+1, e);
    return root;
}

// 8 3 10 1 6 14 4 7 13 -1 (-1 only once)
int main() {
    // cout<<"Enter input: ";
    // Node* root = buildBST();

    int arr[] = {1,2,3,4,5,6};
    Node* root = ARRtoBST(arr, 0, 5);


    // LinkedList l = BSTtoLL(root);

    // printLL(l.head);

    // printRange(root, 2, 10);
    // cout<<endl;

    // if(isBST(root)) cout<<"Is BST"<<endl;
    // else cout<<"Not BST"<<endl;

    // Node* searchAns = searchBST(root, 5);
    // if (searchAns) cout<<"Data found"<<endl;
    // else cout<<"Not found"<<endl;




    // cout<<"Preorder:";
    // PreOrder(root);
    // cout<<endl;
    // cout<<"Inorder: ";
    // InOrder(root);
    // cout<<endl;
    // cout<<"Postorder: ";
    // PostOrder(root);
    // cout<<endl;

    cout<<"Level order: \n";
    LevelOrder(root);
    cout<<endl;

    // Pair p = isBalanced(root);
    // if(p.isBal) cout<<"Balanced"<<endl;
    // else cout<<"Not balanced"<<endl;


    return 0;
}