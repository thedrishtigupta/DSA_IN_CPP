
#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool isPossible(vector<int>& arr, int m, int cows) {
    int n = arr.size();
    int cnt = 1, last = arr[0];

    for(int i = 1; i < n; i++) {
        if (arr[i] - last >= m) {cnt++; last = arr[i];}

        if( cnt >= cows) return true;
    }
    return false;
}
int maxDistance(vector<int>& arr, int cows) {
    sort(begin(arr), end(arr));
    int i = 0, j = arr.back() - arr.front();

    while(i <= j) {
        int m = i + (j-i)/2;

        if (isPossible(arr, m, cows)) i = m+1;
        else j = m-1;
    }
    return j;
}
int main() {
    vector<int> arr = {0, 3, 4, 7, 10 ,9};
    int cows = 4;

    cout<<maxDistance(arr, cows);
    return 0;
}