#include <iostream>
#include<algorithm>
#include <queue>
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

class Pair {
    public:
    int height;
    int dia;
};


Node* buildTree() {
    int d;
    cin>>d;
    if (d == -1) return NULL;

    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();

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

// 4 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main() {
	int n; cin>>n;

    Node* root = buildTree();

    cout<<"Preorder:";
    PreOrder(root);
    cout<<endl;
    cout<<"Inorder: ";
    InOrder(root);
    cout<<endl;
    cout<<"Postorder: ";
    PostOrder(root);
    cout<<endl;

    return 0;
}