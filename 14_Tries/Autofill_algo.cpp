#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Node {
    public:
    unordered_map<char, Node*> h;
    bool isEnd;
    char ch;

    Node() {
        ch = '\0';
        isEnd = false;
    }

    Node(char c) {
        ch = c;
        isEnd = false;
    }
};

class Trie {
    public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void addWord(string word) {
        Node* temp = root;

        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(temp->h.count(ch) == 0) {
                temp->h[ch] = new Node(ch);
            }
            temp = temp->h[ch];
        }
        temp->isEnd = true;
    }

    void autofillHelper(Node* temp, string &x) {

        if(temp->isEnd) cout<<x<<endl;

        for(auto p : temp->h) {

            x.push_back(p.first);

            autofillHelper(p.second, x);

            x.pop_back(); // backtrack because we are passing original string x, if we use string x only, then no backtrack required
        }
    }

    void autofill(string word) {
        Node* temp = root;

        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if(temp->h.count(ch) == 0) return ;

            temp = temp->h[ch];
        }
        string x = word;
        autofillHelper(temp, x);
    }

    bool searchWord(string word) {
        Node* temp = root;

        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if(temp->h.count(ch) == 0) return false;

            temp = temp->h[ch];
        }
        return temp->isEnd;
    }
};
int main() {
    Trie t;
    t.addWord("Her");
    t.addWord("He");
    t.addWord("Him");
    t.addWord("Pan");

    t.autofill("H");
    return 0;
}