
#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool canPaint(vector<int>& arr, int m ,int k) {
    int cnt = 1, sum = 0;

    for(int val : arr) {
        if (val > m) return false;

        if(sum + val <= m) sum += val;
        else {cnt++; sum = val;}
    }
    return cnt <= k;
}
int painter(vector<int>& arr, int k) {
    int i = *max_element(begin(arr), end(arr));
    int j = accumulate(begin(arr), end(arr), 0);

    while(i <= j) {
        int m = i + (j-i)/2;

        if(canPaint(arr, m , k)) j = m-1;
        else i = m+1;
    }
    return i;
}
int main() {
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;

    cout<<painter(arr, k);
    return 0;
}