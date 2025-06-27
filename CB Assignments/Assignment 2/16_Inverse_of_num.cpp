#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    cin>>num;

    int place = 1, ans = 0;

    while (num > 0) {
        int digit = num % 10;
        ans += place * pow(10, digit-1);
        num /= 10;
        place++;
    }

    cout<<ans;
    return 0;
}