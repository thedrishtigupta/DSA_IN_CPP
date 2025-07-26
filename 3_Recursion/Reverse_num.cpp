#include <iostream>
using namespace std;
int reverse(int num, int ans = 0) {
    if (num <= 0) return ans;

    ans = (ans*10) + (num % 10);
    return reverse(num/10, ans);
}
int main() {
    int num = 762;
    cout<<reverse(num);
    return 0;
}