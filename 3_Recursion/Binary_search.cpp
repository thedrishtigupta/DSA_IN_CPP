#include <iostream>
using namespace std;
int bs(int* arr, int tar, int j, int i = 0) {
    if (i > j) return -1;

    int m = i + ((j-i)/2);
    if (arr[m] == tar) return m;
    else if (arr[m] > tar) j = m-1;
    else i = m+1;

    return bs(arr, tar, j , i);
}
int main() {
    int arr[] = {2, 3, 5, 7, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int tar = 3;

    cout<<bs(arr, tar, n-1);
    return 0;
}