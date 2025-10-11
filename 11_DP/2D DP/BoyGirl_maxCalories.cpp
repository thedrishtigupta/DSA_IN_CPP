#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int maxCal(vector<vector<int>& cal, int n, int m) {
    vector<vector<int> BS(n, vector<int>(m));
    vector<vector<int> GS(n, vector<int>(m));
    vector<vector<int> BD(n, vector<int>(m));
    vector<vector<int> GD(n, vector<int>(m));

    // Building BS
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) {
                BS[i][j] = cal[i][j];
            } else {
                BS[i][j] = max(i - 1 >= 0 ? BS[i-1][j] : INT_MIN, j - 1 >= 0 ? BS[i][j-1] : INT_MIN) + cal[i][j];
            }
        }
    }

    // Building GS
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            if(i == n-1 and j == 0) {
                BS[i][j] = cal[i][j];
            } else {
                BS[i][j] = max(i - 1 >= 0 ? BS[i-1][j] : INT_MIN, j - 1 >= 0 ? BS[i][j-1] : INT_MIN) + cal[i][j];
            }
        }
    }

    // Building BD
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(i == n-1 and j == m-1) {
                BS[i][j] = cal[i][j];
            } else {
                BS[i][j] = max(i + 1 >= n ? BS[i+1][j] : INT_MIN, j + 1 >= m ? BS[i][j+1] : INT_MIN) + cal[i][j];
            }
        }
    }

    // Building GD
    for(int i = 0; i < n; i++) {
        for(int j = m-1; j >= 0; j--) {
            if(i == 0 and j == m-1) {
                BS[i][j] = cal[i][j];
            } else {
                BS[i][j] = max(i + 1 >= n ? BS[i+1][j] : INT_MIN, j + 1 >= m ? BS[i][j+1] : INT_MIN) + cal[i][j];
            }
        }
    }

    int ans = 0;
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            int op1 = BS[i-1][j] + BD[i+1][j] + GS[i][j-1] + GD[i][j+1];
            int op2 = BS[i][j-1] + BD[i][j+1] + GS[i+1][j] + GD[i-1][j];
            ans = max(ans, max(op1, op2));
        }
    }

    return ans;
}

int main() {
    int n, m; cin>>n>>m;

    vector<vector<int>> cal(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>cal[i][j];
        }
    }

    cout<<maxCal(cal, n, m)<<endl;

    return 0;
}