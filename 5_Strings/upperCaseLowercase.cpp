#include <iostream>
using namespace std;

int main() {
    
    char ch;
    cout<<"Enter a character: ";
    cin>>ch;

    if (ch >= 97 && ch <= 122) {
        cout<<"Lowercase char"<<endl;
    } else if (ch >= 65 && ch <= 90) {
        cout<<"Uppercase char"<<endl;
    } else {
        cout<<"Invalid"<<endl;
    }
    cout<<(int)ch<<endl;
    
    return 0;
}