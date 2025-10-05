#include <iostream>
#include<vector>
#include<climits>
using namespace std;

// int topDown(vector<vector<int>>& cost, int n, int m, int i = 0, int j = 0) {


//     if(dp[i][j] != -1) return dp[i][j];

//     int op1 = topDown(cost, n, m, i, j-1);
//     int op2 = topDown(cost, n, m, i-1, j);

//     return min(op1, op2) + cost[i][j];
// }
int bottomUp(vector<vector<int>>& cost, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) {
                dp[i][j] = cost[i][j];
            } else {
                dp[i][j] = min(i - 1 >= 0 ? dp[i-1][j] : INT_MAX, j - 1 >= 0 ? dp[i][j-1] : INT_MAX) + cost[i][j];
            }
        }
    }
    return dp[n-1][m-1];
}

// 1 1 3 2 8 1 1 5 4 6 1 1 9 15 22 1
int main() {
    int n, m; cin>>n>>m;

    vector<vector<int>> cost(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>cost[i][j];
        }
    }

    cout<<bottomUp(cost, n, m)<<endl;

    return 0;
}