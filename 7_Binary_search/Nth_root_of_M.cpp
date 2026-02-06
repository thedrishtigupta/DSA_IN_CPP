#include <iostream>
#include <cmath>
using namespace std;
int root (int n, int m) {
    int i = 1, j = m;

    while (i <= j) {
        int mid = i + ((j-i)/2);
        int power = 1;
        for(int i = 0; i < n; i++) {
            power *= mid;
            if (power > m) break;
        }
        if (power == m) return mid;
        else if (power < m) i = mid+1;
        else j = mid-1;
    }
    return -1;
}
int main() {
    int n = 3;
    int m = 27;
    cout<<root(n, m);
    return 0;
}