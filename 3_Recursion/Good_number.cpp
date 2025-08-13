#include <iostream>
using namespace std;
long long power(int x, int n, long long ans = 1) {
    if (n == 0) return ans;

    if (n % 2 == 1) ans *= x;

    return power(1LL*x*x, n/2, ans);
}
int main() {
    int n;
    cin>>n;
    // if (n == 0) {cout<< 0; return 0;}
    int even, odd;

    if (n % 2 == 0) {even = n/2; odd = n/2;}
    else {even = n/2 + 1; odd = n/2;}

    cout<<(power(5, even) * power(4, odd)) % (1000000000 + 7);


    return 0;
}