#include <iostream>
#include<vector>
using namespace std;

int topDown (int n, vector<int>& dp) {
    if(n == 0 || n == 1) {
        dp[n] = n;
        return n;
    }

    if (dp[n] != -1) return dp[n];

    return dp[n] = topDown(n-1, dp) + topDown(n-2, dp);
}

int bottomUp(int n) {
    vector<int> dp(n+1); // +1 is important!!
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}
int main() {
    int n; cin>>n;
    vector<int> dp(n+1, -1);

    // for(int i = 0; i <= n; i++) cout<<dp[i]<<" ";

    cout<<endl<<topDown(n, dp)<<endl;;
    //for(int i = 0; i <= n; i++) cout<<dp[i]<<" ";
    cout<<bottomUp(n)<<endl;
    return 0;
}