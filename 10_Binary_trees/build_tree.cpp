#include <iostream>
#include<algorithm>
#include <queue>
#include<unordered_map>
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

void maxFreqSum (Node* root, unordered_map<int, int>& freq) {
    if(!root) return freq[root->data] = 0;

    
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



int countNodes(Node* root) {
    if(!root) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int heightTree(Node* root) {
    if(!root) return 0;

    return max(heightTree(root->left), heightTree(root->right))+1;
}

int diameterTree(Node* root) {
    if(!root) return 0;

    int op1 = heightTree(root->left) + heightTree(root->right); // max diameter via root node
    int op2 = diameterTree(root->left); // LST ka maximum diameter
    int op3 = diameterTree(root->right); // RST ka maximum diameter

    return max(op1, max(op2, op3));
}

Pair fastDiameter(Node* root) {
    Pair p;
    if (!root) {
        p.height = p.dia = 0;
        return p;
    }

    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) +1;

    int op1 = left.height + right.height;
    int op2 = left.dia;
    int op3 = right.dia;

    p.dia = max(op1, max(op2, op3));

    return p;
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

void mirror(Node* root) {
    if(!root) return;

    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}
// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main() {
    cout<<"Enter input: ";
    
    Node* root = buildTree();

    unordered_map<int, int> freq;
    // cout<<"Total nodes = "<<countNodes(root)<<endl;
    // cout<<"Height of tree = "<<heightTree(root)<<endl;
    // cout<<"Diameter of tree = "<<diameterTree(root)<<endl;
    // Pair p = fastDiameter(root);
    // cout<<"Fast height= "<<p.height<<endl;
    // cout<<"Fast diameter= "<<p.dia<<endl;
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

    // mirror(root);
    
    // cout<<"Level order: \n";
    // LevelOrder(root);
    // cout<<endl;

    // if(searchNode(root, 5)) cout<<"Key found"<<endl;
    // else cout<<"Not present"<<endl;

    
    
    return 0;
}