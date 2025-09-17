#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalancedPrimal(string a) {
    stack<char> s;

    for (int i = 0; a[i]; i++) {
        char ch = a[i];
        switch(ch) {
            case '(':
            case '{':
            case '[': s.push(ch); break;
            case ')' :
                if (!s.empty() && s.top() != '(') return false;
                s.pop(); break;
            case '}' :
                if (!s.empty() && s.top() != '{') return false;
                s.pop(); break;
            case ']' :
                if (!s.empty() && s.top() != '[') return false;
                s.pop(); break;
        }
    }
    return s.empty();
}

bool isBalanced(string a) {
    stack<char> s;

	for (auto i : a) {
		if (i == '{' || i == '[' || i == '(') s.push(i);
		else {
			if (s.empty() or (s.top()=='(' and i!=')') or (s.top()=='{' and i!='}') or (s.top()=='[' and i!=']')) return false;
			s.pop();
		}
	}
	return s.empty();
}
int main() {
    string a = "[{a+b*(c+d)*(d+f)}";

    if(isBalanced(a)) cout<<"Balanced"<<endl;
    else cout<<"Not balanced"<<endl;


    return 0;
}