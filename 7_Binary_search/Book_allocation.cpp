
#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;

bool canAllot(vector<int>& arr, int m, int s) {
    int ans = 1, pages = 0;

    for(int val : arr) {
        if (val > m) return false;
        if(pages + val <= m) pages += val;
        else {ans++; pages = val;}
    }
    return ans <= s;
}
int book_allot(vector<int>& arr, int s) {
    if (s > arr.size()) return -1;
    int i = *max_element(begin(arr), end(arr)), j = accumulate(begin(arr), end(arr), 0);

    while(i <= j) {
        int m = i + (j-i)/2;

        if(canAllot(arr, m, s)) j = m-1;
        else i = m+1;
    }
    return i;
}
int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int s = 4;

    cout<<book_allot(arr, s);
    return 0;
}