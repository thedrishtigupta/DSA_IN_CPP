#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    if (n > 1000) return 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= i; j++) {
            if (i == 1) {
                cout<<1; break;
            }
            if (j == 1 || j == i) {
                cout << i-1;
            } else {
                cout<< 0;
            }
        }
        cout<< endl;
    }
    return 0;
}
