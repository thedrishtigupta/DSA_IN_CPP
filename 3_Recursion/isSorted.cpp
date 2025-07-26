#include <iostream>
using namespace std;
bool ans(int arr[], int n) {
    if (n <= 1) return true;

    if (arr[0] <= arr[1] && ans(arr+1, n-1) == true) return true;
    else return false;
}
bool ans2 (int arr[], int n) {
    if (n <= 1) return true;

    if (arr[n-1] >= arr[n-2] && ans(arr, n-1) == true) return true;
    else return false;
}
int main() {
    int arr[] = {1, 2, 5 , 6 , 7};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<<ans(arr, n);
    return 0;
}