#include <iostream>
#include<vector>
using namespace std;

int solve (int n, vector<int>& dp) {
    if(n == 0 || n == 1) {
        dp[n] = n;
        return n;
    }

    if (dp[n] != -1) return dp[n];

    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}
int main() {
    int n; cin>>n;
    vector<int> dp(n+1, -1);

    for(int i = 0; i <= n; i++) cout<<dp[i]<<" ";

    cout<<endl<<solve(n, dp)<<endl;;
    for(int i = 0; i <= n; i++) cout<<dp[i]<<" ";
    return 0;
}