#include <iostream>
using namespace std;
long long power(int x, int n) {
    if(n == 0) return 1;

    return x * power(x, n-1);
}
int main() {
    int x = 5;
    int n = 3;
    cout<<power(x,n);
    return 0;
}