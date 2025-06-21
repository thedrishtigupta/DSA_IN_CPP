#include <iostream>
using namespace std;

void pattern1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern3(int n) {
    for (int i = 1; i <= n; i++) {
        //space
        for (int j = 1; j <= n-i; j++) {
            cout <<"  ";
        }
        //star
        for (int j = 1; j <= 2*i-1; j++) {
            cout <<"* ";
        }
        cout << endl;
    }
}
void pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        //space
        for (int j = 1; j <= i-1; j++) {
            cout <<"  ";
        }
        //star
        for (int j = 1; j <= 2*(n-i)+1; j++) {
            cout <<"* ";
        }
        cout << endl;
    }
}
void pattern5(int n) {
    for (int i = 1; i <= n; i++) {
        //space
        for (int j = 1; j <= n-i; j++) {
            cout <<"  ";
        }
        //star
        for (int j = 1; j <= 2*i-1; j++) {
            cout <<"* ";
        }
        //space
        for (int j = 1; j <= n-i; j++) {
            cout <<"  ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        //space
        for (int j = 1; j <= i-1; j++) {
            cout <<"  ";
        }
        //star
        for (int j = 1; j <= 2*(n-i)+1; j++) {
            cout <<"* ";
        }
        //space
        for (int j = 1; j <= i-1; j++) {
            cout <<"  ";
        }
        cout << endl;
    }
}
void pattern6(int n) {
    for (int i = 1; i <= 2*n-1; i++) {
        int stars = i;
        if (i > n) {
            stars = 2*n-i;
        }
        for (int j = 1; j <= stars; j++) {
            cout <<"* ";
        }
        cout << endl;
    }
}
void pattern7(int n) {
    for (int i = 1; i <=n ; i++) {
        for (int j = 1; j <= i; j++) {
            cout<<"* ";
        }
        cout<<"  ";
        for(int j = 1; j <= n-i+1; j++) {
            cout<<"* ";
        }
        cout<<" ";
        for(int j = 1; j <= n-i+1; j++) {
            cout<<"* ";
        }
        cout<<"  ";
        for (int j = 1; j <= i; j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern8(int n) {
    for (int i = 1; i<= n; i++) {
        for (int star= 1; star <= n-i+1; star++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern9(int n) {
    for (int i = 1; i<= n; i++) {
        for (int space = 1; space <= n-i; space++) {
            cout<<"  ";
        }
        for (int star = 1; star <= i; star++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern10(int n) {
    for (int i = 1; i<=n; i++) {
        for (int space = 1; space <= i-1; space++) {
            cout<<"  ";
        }
        for(int star = 1; star <= n-i+1; star++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern11(int n) {
    for (int i = 1; i <= n; i++) {
        for (int star = 1; star <= i; star++) {
            cout<<"* ";
        }
        for (int j = 1; j <= 2*(n-i)-1; j++) {
            if (i == n) break;
            cout<<"  ";
        }
        for (int star = 1; star <= i; star++) {
            if (i == n && star == n) break;
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern12(int n) {
    for (int i = 1; i <= n; i++) {
        for (int star = 1; star <= n-i+1; star++) {
            cout<<"* ";
        }
        for (int j = 1; j <= 2*i-3; j++) {
            if (i == 1) break;
            cout<<"  ";
        }
        for (int star = 1; star <= n-i+1; star++) {
            if (i == 1 && star == n) break;
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern13(int n) {
    //first half
    for (int i = 1; i <= n; i++) {
        //star
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        //space
        for (int j = 1; j <= 2*(n-i); j++) {
            cout << "  ";
        }
        //star
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout<<endl;
    }
    //second half
    for (int i = 1; i < n; i++) {
        //star
        for (int j = 1; j <= n-i; j++) {
            cout << "* ";
        }
        //space
        for (int j = 1; j <= 2*i; j++) {
            cout << "  ";
        }
        //star
        for (int j = 1; j <= n-i; j++) {
            cout << "* ";
        }
        cout<<endl;
    }    
}
void pattern14(int n) {
    for (int i = 1; i <= n; i++) {
        int star, space;
        if ( i> n/2) {
            space = (2*i - n - 1) / 2;
            star = 2*(n-i) + 1;
        } else {
            space = (n + 1 - 2*i) / 2;
            star = 2*i - 1;
        }
        for (int j = 1; j<= space; j++) {
            cout<<"  ";
        }
        for (int j = 1; j<= star; j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    pattern14(n);
    return 0;
}