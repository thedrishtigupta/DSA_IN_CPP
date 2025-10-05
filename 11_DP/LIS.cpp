#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int bottomUp(vector<int>& arr, int n) {
    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++) {
        for(int j = n-1; j >= 0; j--) {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] +1);
        }
    }
    return dp[n-1];
}
int main() {
    int n; cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];

    cout<<bottomUp(arr, n)<<endl;
    return 0;
}