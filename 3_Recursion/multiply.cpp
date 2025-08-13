#include <iostream>
using namespace std;
int mult(int a, int b, int ans = 0) {
    if (b == 0) return ans;

    return mult(a, b-1, ans+a);
}
int mult(int a, int b) {
    if (b == 0) return 0;

    return a + mult(a, b-1);
}
int main() {
    int a = 4, b = 5;
    cout<<mult(a, b);
    return 0;
}