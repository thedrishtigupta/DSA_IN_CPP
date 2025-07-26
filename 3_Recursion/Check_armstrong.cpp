#include <iostream>
#include<cmath>
using namespace std;
bool checkArm (int num, int n, int org, int ans = 0) {

    if (num <= 0) return ans == org;

    ans += (int)(pow(num % 10, n)+0.5);
    return checkArm(num/10, n, org, ans);
}
int main() {
    int num = 153;
    int n = (int)(log10(num)+1);
    cout<<checkArm(num, n, num,0);
    return 0;
}