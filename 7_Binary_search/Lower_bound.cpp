#include <iostream>
#include <vector>
using namespace std;
int lower_bound(vector<int> arr, int x) {
    int n = arr.size();
    int i = 0, j = n-1, ans = n;
    while (i <= j) {
        int m = i + ((j-i)/2);
        if (x > arr[m]) i = m+1;
        else if (x <= arr[m]) {
            j = m -1;
            ans = m;
            if (arr[m-1] != x) break;
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
        if (x > arr[m]) i = m+1;
        else if (x <= arr[m]) {
            j = m -1;
            ans = m;
            if (arr[m-1] != x) break;
        }
    }
    cout<<ans;
    return 0;
}