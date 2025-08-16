#include <iostream>
using namespace std;

int solve (int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    return solve(n-1) + solve(n-2) + solve(n-3);
}

int stairs (int n, int k) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += stairs(n-i, k);
    }
    return ans;
}

int main() {
    int n = 4, k = 3;
    cout<<solve(n)<<endl;
    cout<<stairs(n, k)<<endl;
    return 0;
}