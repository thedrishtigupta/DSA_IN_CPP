#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int rotatedIdx (vector<int>& a) {
    int i = 0, j = a.size()-1;
    int ans = INT_MAX, idx = -1;

    while(i <= j) {
        if(a[i] <= a[j]) {
            if (a[i] < ans) {
                ans = a[i];
                idx = i;
            }
            return idx;
        }

        int m = i + (j-i)/2;
        
        if(a[i] <= a[m]) {
            if(a[i] < ans) {
                ans = a[i];
                idx = i;
            }
            i=m+1;
        } else {
            if(a[m] < ans) {
                ans = a[m];
                idx = m;
            }
            j = m-1;
        }
    }
    return idx;
}

int minIdx(vector<int>& a) {
    int i = 0, j = a.size() - 1;

    while (i < j) {
        int m = i + (j - i) / 2;

        if (a[m] > a[j]) {
            i = m + 1;
        } else {
            j = m;
        }
    }
    return i;
}
int main() {
    vector<int> arr = {4, 5, 6, 0, 1, 2, 3};
    

    cout<<minIdx(arr);
    return 0;
}