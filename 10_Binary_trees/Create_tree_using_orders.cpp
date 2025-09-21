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

int pre[] = {8, 10, 1, 6, 4, 7, 3, 14, 13};
int post[] = {1,4,7,6,10,13,14,3,8};

Node* inPreCreate(int* in, int s, int e, int* pre, int& k) {
    if (s > e) return NULL;

    Node* root = new Node(pre[k++]);
    int j = -1;
    for(int i = s; i <= e; i++) {
        if (in[i] == root->data){
            j = i; break;
        }
    }
    if (j == -1) return NULL;
    root->left = inPreCreate(in, s, j-1, pre, k);
    root->right = inPreCreate(in, j+1, e, pre, k);

    return root;
}

Node* inPostCreate(int* in, int s, int e, int* post, int&m) {
    if(s > e) return NULL;
    Node* root = new Node(post[m--]);
    int j = -1;
    for(int i = s; i <= e; i++) {
        if (in[i] == root->data){
            j = i; break;
        }
    }
    if (j == -1) return NULL;
    root->right = inPostCreate(in, j+1, e, post, m);
    root->left = inPostCreate(in, s, j-1, post, m);
    

    return root;
}

int heightTree(Node* root) {
    if(!root) return 0;

    return max(heightTree(root->left), heightTree(root->right))+1;
}


Node* searchNode(Node* root, int tar) {
    if(!root) return NULL;

    if (root->data == tar) return root;
    
    Node* ans = searchNode(root->left, tar); //LST, else if case
    if (ans!= NULL) return ans;

    return searchNode(root->right, tar); // RST or not present, else case
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

// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main() {
    int in[] = {1, 10, 4, 6, 7, 8, 3, 13, 14};
    int k = 0;
    Node* root = inPreCreate(in, 0, 8, pre, k);
    int m = 8;
    Node* root2 = inPostCreate(in, 0, 8, post, m);

    cout<<"Level order: \n";
    LevelOrder(root);
    cout<<"Level order 2: \n";
    LevelOrder(root2);
    

    
    
    return 0;
}