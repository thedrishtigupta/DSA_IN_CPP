#include <iostream>
using namespace std;

int square_root(int n) {
    int i = 1, j = n;

    while (i <= j) {
        long long m = i + ((j-i)/2);
        long long val = m*m;

        if (val == n) return m;
        else if (val > n) j = m-1;
        else i = m+1; 
    }
    return j;
}
int main() {
    int n = 28;
    cout<<square_root(n);
    return 0;
}