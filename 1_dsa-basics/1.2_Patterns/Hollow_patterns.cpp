#include <iostream>
using namespace std;

void pattern1(int n) { // hollow diamond 2 outer loops
    for (int i = 1; i <n ; i++) {
        int star = n-i+1, space;
        if (i == 1) {
            space = 0;
        } else {
            space = 2*i-3;
        }
        //star
        for (int j = 1; j <= star; j++) {
            cout <<"* ";
        }
        //space
        for (int j = 1; j <= space; j++) {
            cout <<"  ";
        }
        //star
        for (int j = 1; j <= star; j++) {
            if(i == 1 && j == star) {
                break;
            }
            cout <<"* ";
        }
        cout<<endl;
    }
    for (int i = 1; i <=n ; i++) {
        int star = i, space;
        if (i == n) {
            space = 0;
        } else {
            space = 2*(n-i)-1;
        }
        //star
        for (int j = 1; j <= star; j++) {
            cout <<"* ";
        }
        //space
        for (int j = 1; j <= space; j++) {
            cout <<"  ";
        }
        //star
        for (int j = 1; j <= star; j++) {
            if(i == n && j == star) {
                break;
            }
            cout <<"* ";
        }
        cout<<endl;
    }
}
void pattern2(int n) { // hollow diamond 1 outer loop
    for (int i = 1; i <= 2*n-1 ; i++) {
        int star, space;
        if (i >= n) {
            star = i-n+1;
            space = (4*n) - (2*i) - 3;
            
        } else {
            star = n-i+1;
            space = 2*i - 3;
        }
        if (i == 1 || i ==2*n-1) {
            space = 0;
        }
        //star
        for (int j = 1; j <= star; j++) {
            cout <<"* ";
        }
        //space
        for (int j = 1; j <= space; j++) {
            cout <<"  ";
        }
        //star
        for (int j = 1; j <= star; j++) {
            if(space == 0 && j == star) {
                break;
            }
            cout <<"* ";
        }
        cout<<endl;
    }
}
void pattern3(int n) {
    for (int i = 1; i <= n; i++) {
        int star, space;
        if ( i> n/2) {
            star = (2*i - n - 1) / 2;
            space = 2*(n-i) + 1;
        } else {
            star = (n + 1 - 2*i) / 2;
            space = 2*i - 1;
        }
        for (int j = 1; j<= star; j++) {
            cout<<"* ";
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
void pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i==1 || i == n || j == 1 || j == n) {
                cout <<"* ";
            } else {
                cout <<"  ";
            }
        }
        cout<<endl;
    }
}
void pattern5(int n) {
    for (int i = 1; i <= n; i++) {
        int space, star;
        if (i > n/2) {
            space = 2*(n-i) - 1;
            star = (n - space) /2;
        } else {
            space = 2*i - 3;
            star = (n - space) /2;
        }
        if (i == 1 || i == n) space = 0;

        for (int j = 1; j <= star; j++) {
            cout<<"* ";
        }
        for (int j = 1; j<= space; j++) {
            cout<<"  ";
        }
        for (int j = 1; j <= star; j++) {
            if (space == 0 && j == star) break;
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern6(int n) { //satvik
    for (int i = 1; i <= 2*n-1; i++) {
        for (int j = 1; j <= 2*n-1; j++) {
            if (i== n || j == n || (j==1 && i <= n) || (i==1 && j > n) || (j== 2*n-1 && i > n) || (i == 2*n-1 && j < n)) {
                cout<<"* ";
            } else {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void pattern7(int n) { //cross diagonals
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j<= n; j++) {
            if (i == j || i+j == n+1) {
                cout<<"* ";
            } else {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void pattern8(int n) {
    for (int i = 1; i <= 2*n - 1; i++) {
        int space, star;
        if (i <= n) {
            space = n-i;
            star = n-i+1;
        } else {
            space = i-n;
            star = i-n+1;
        }
        for (int j = 1; j <= space; j++) {
            cout<<"  ";
        }
        for (int j = 1; j <= star; j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin >> n;
    return 0;
}