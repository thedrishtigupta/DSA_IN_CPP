#include <iostream>
using namespace std;
int upper_bound(vector<int> arr, int x) {
    int n = arr.size();
    int i = 0, j = n-1, ans = n;
    while (i <= j) {
        int m = i + ((j-i)/2);
        if (x >= arr[m]) i = m+1;
        else {
            j = m - 1;
            ans = m;
        }
    }
    return ans;
}
int main() {
    int arr[] = {1, 2, 2, 2, 2, 3, 5};
    int n = sizeof (arr)/ sizeof(arr[0]);
    int x = 2;

    int i = 0, j = n-1, ans = n;
    while (i <= j) {
        int m = i + ((j-i)/2);
        if (x >= arr[m]) i = m+1;
        else {
            j = m - 1;
            ans = m;
        }
    }
    cout<<ans;
    return 0;
}