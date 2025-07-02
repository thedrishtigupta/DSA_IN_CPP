#include<iostream>
using namespace std;

int main() {
	int n;
    cin>>n;
    int space, star;
    for (int i = 1; i <= n; i++) {
        if (i > n/2) {
            space = (2*i - n - 1)/2;
            star = 2*(n-i) + 1;
        } else {
            space = (n + 1 - 2*i)/2;
            star = 2*i - 1;
        }
        for (int j = 1; j <= space; j++) {
            cout<<"  ";
        }
        for (int j = 1; j <= star; j++) {
            if (j == 1 || j == star) cout <<"* ";
            else cout<<"  ";
        }
        cout<<endl;
    }
	return 0;
}