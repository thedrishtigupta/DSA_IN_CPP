#include <iostream>
using namespace std;

void pattern1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout <<j<<" ";
        }
        cout << endl;
    }
}
void pattern2(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout <<i<<" ";
        }
        cout << endl;
    }
}
void pattern3(int n) {
    int num;
    for (int i = 1; i <= n; i++) {
        (i % 2 == 0) ? num = 0 : num = 1;
        for (int j = 1; j <= i; j++) {
            cout<<num<<" ";
            num = 1 - num;
        }
        cout<<endl;
    }
}
void pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i+1; j++) {
            cout <<j<<" ";
        }
        cout << endl;
    }
}
void pattern5(int n) {
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout<<j <<" ";
        }
        for (int j = 1; j <= 2*(n-i); j++) {
            cout<<"  ";
        }
        for (int j = i; j >= 1; j--) {
            cout<<j <<" ";
        }
        cout<<endl;
    }
}
void pattern6(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++, num++) {
            cout <<num<<" ";
        }
        cout << endl;
    }
}
void pattern7(int n) {
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = 0; j < 2*n-1; j++) {
            int top = i, left = j, right = (2*n) -2 -j, bottom = (2*n) -2 - i;
            cout << n - min(min(top, bottom), min(left,right)) <<" ";
        }
        cout<<endl;
    }
}
void pattern8(int n) {
    for (int i = 1; i <=n ; i++) {
        // space
        for (int j = 1; j <= n-i; j++) {
            cout<<"  ";
        }
        for (int j = 1; j<= 2*i - 1; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void pattern9(int n) {
    for (int i = 1; i <= n; i++) {
        int num = 1;
        for (int space = 1; space <= n-i; space++) {
            cout<<"  ";
        }
        for (int j = 1; j <= 2*i-1; j++) {
            cout<<num <<" ";
            j > (2*i-1)/2 ? num-- : num++;
        }
        cout<<endl;
    }
}
void pattern10(int n) {
    for (int i = 1; i <= n; i++) {
        int num = i;
        for (int space = 1; space <= n-i; space++) {
            cout<<"  ";
        }
        for (int j = 1; j <= 2*i-1; j++) {
            cout<<num <<" ";
            j > (2*i-1)/2 ? num-- : num++;
        }
        cout<<endl;
    }
}
void pattern11(int n) {
    for (int i = 1; i <= n; i++) {
        for (int space = 1; space <= n-i; space++) {
            cout<<"  ";
        }
        for (int j = 1; j <= 2*i-1; j++) {
            if (j == 1 || j == 2*i-1) cout<<i <<" ";
                else cout<<0 <<" ";
            
        }
        cout<<endl;
    }
}
void pattern12(int n) {
    for (int i = 1; i <= n; i++) {
        for (int space = 1; space <= n-i; space++) {
            cout<<"  ";
        }
        int num = n-i+1;
        for (int j = 1; j <= 2*i-1; j++) {
            if (j == i) {
                cout<<0<<" ";
            } else cout<<num<<" ";
            j > (2*i-1)/2 ? num-- : num++;
        }
        cout<<endl;
    }
}
void pattern13(int n) {
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j<= n; j++) {
            cout<<n-j+1<<" ";
        }
        cout<<endl;
    }
}
void pattern14(int n) {
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j<= n; j++) {
            if (i+ j == n+1) {
                cout<<"* ";
            } else {
                cout<<n-j+1<<" ";
            }
        }
        cout<<endl;
    }
}
void pattern15(int n) {
    for (int i = 1; i<= 2*n-1; i++) {
        int col, num;
        if (i > n) {
            col = 4*n - 2*i - 1;
            num = 2*n-i;
        } else {
            col = 2*i - 1;
            num = i;
        }
        for (int j = 1; j <= col; j++) {
            if (j % 2 != 0) {
                cout<<num<<" ";
            } else {
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    pattern15(n);
    
    return 0;
}