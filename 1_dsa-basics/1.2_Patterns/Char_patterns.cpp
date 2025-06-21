#include <iostream>
using namespace std;

void pattern1(int n) {
    for (int i = 1; i <= n; i++) {
        char ch = 'A';
        for (int j = 1; j <= 2*(n-i)+1; j++) {
            cout<<ch<<" ";
            (j <= (2*(n-i)+1)/2) ? ch++ : ch--;
        }
        cout<<endl;
    }
}
void pattern2(int n) {
    for (int i = 1; i <= n; i++) {
        for (char j = 'A'; j <='A' + i -1; j++) {
            cout << j <<" ";
        }
        cout << endl;
    }
}
void pattern3(int n) {
    for (int i = 1; i <= n; i++) {
        for (char j = 'A'; j <='A' + n - i ; j++) {
            cout << j <<" ";
        }
        cout << endl;
    }
}
void pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        char ch = 'A' + i-1;
        for (int j = 1; j <=i ; j++) {
            cout << ch <<" ";
        }
        cout << endl;
    }
}
void pattern5(int n) {
    for (int i = 1; i<= n; i++) {
        for (int space = 1; space <= n-i; space++) {
            cout<<"  ";
        }
        char ch = 'A';
        for (int j = 1; j<= 2*i - 1; j++) {
            cout<<ch<<" ";
            (j > (2*i - 1)/2) ? ch-- : ch++;
        }
        cout<<endl;
    }
}
void pattern6(int n) {
    for (int i = 1; i <= n; i++) {
        char ch = 'A' + n - 1;
        for (char j = ch - i + 1; j <=ch ; j++) {
            cout << j <<" ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    pattern5(n);
    return 0;
}