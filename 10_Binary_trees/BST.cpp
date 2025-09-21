#include <iostream>
#include<queue>
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

Node* insertBST(Node* root, int d) {
    if(!root) {
        root = new Node(d);
        return root;
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

// 8 3 10 1 6 14 4 7 13 -1 (-1 only once)
int main() {
    cout<<"Enter input: ";
    Node* root = buildBST();


    cout<<"Preorder:";
    PreOrder(root);
    cout<<endl;
    cout<<"Inorder: ";
    InOrder(root);
    cout<<endl;
    cout<<"Postorder: ";
    PostOrder(root);
    cout<<endl;

    cout<<"Level order: \n";
    LevelOrder(root);
    cout<<endl;

    return 0;
}