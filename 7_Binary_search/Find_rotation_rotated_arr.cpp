#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int rotated(vector<int>& a) {
    int i = 0, j = a.size()-1;
    int ans = INT_MAX, index = a.size();

    while (i <= j) {
        if (a[i] <= a[j]) {
            if (a[i] < ans) {}
            ans = min(ans, a[i]);
            if (ans == a[i]) index = i;
            return index;
        }

        int m = i + ((j-i)/2);
        if (a[i] <= a[m]) {
            ans = min(ans, a[i]);
            if (ans == a[i]) index = i;
            i = m+1;
        }
        else {
            ans = min(ans, a[m]);
            if (ans == a[m]) index = m;
            j = m-1;
        }
    }
    return index;
}
int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    

    cout<<rotated(arr);
    return 0;
}