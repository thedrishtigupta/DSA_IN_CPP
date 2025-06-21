#include <iostream>
using namespace std;

int main() {
    
    char ch;
    cout<<"Enter a character: ";
    cin>>ch;

    if (ch >= 'a' && ch <= 'z') {
        cout<<"Lowercase char"<<endl;
    } else if (ch >= 'A' && ch <= 'Z') {
        cout<<"Uppercase char"<<endl;
    } else {
        cout<<"Invalid"<<endl;
    }
    cout<<(int)ch<<endl;
    
    return 0;
}