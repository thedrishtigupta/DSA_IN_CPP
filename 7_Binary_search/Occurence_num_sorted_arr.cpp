#include <iostream>
#include<vector>
using namespace std;

int lower_bound(vector<int>& arr, int x) {
    int n = arr.size();
    int i = 0, j = n - 1, ans = n;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (x <= arr[m]) {
            ans = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }
    return ans;
}
int upper_bound(vector<int>& arr, int x) {
    int n = arr.size();
    int i = 0, j = n-1, ans = n;
    while (i <= j) {
        int m = i + ((j-i)/2);
        if (x >= arr[m]) i = m+1;
        else if (x < arr[m]) {
            j = m - 1;
            ans = m;
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {1, 2, 2, 2, 2, 3, 3 ,3 , 4, 5};
    int x;
    cin>>x;

    cout<<upper_bound(arr, x)-lower_bound(arr, x)<<endl;
    return 0;
}