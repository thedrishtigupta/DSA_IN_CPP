

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            if(i == 2) dp[i] = i;
            else dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};