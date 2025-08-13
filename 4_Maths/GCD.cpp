#include <iostream>
using namespace std;
int gcd (int a, int b) {
    if(a == 0) return b;
    if (b == 0) return a;

    return a > b ? gcd(a%b, b) : gcd(a, b%a);
}
int main() {
    cout<<gcd(20, 40)<<endl;
    return 0;
}