#include <iostream>
#include <string>
using namespace std;

string keys[10] = {
    "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wq", "yz"
};

void keypad(string s, int i = 0, string op = "") {
    if (i == s.length()) {
        cout<<op << endl;
        return;
    }

    int d = s[i] - '0';

    for (int j = 0; keys[d][j]; j++) {
        keypad(s, i+1, op+keys[d][j]);
    }
}

int main() {
    string s; cin>>s;
    
    keypad(s);
    return 0;
}