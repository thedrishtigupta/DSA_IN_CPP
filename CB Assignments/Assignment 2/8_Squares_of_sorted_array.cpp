#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;

    if (n < 1 || n > 1e4) return 0;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin>>arr[i];

        if (arr[i] < -1e4 || arr[i] > 1e4) return 0;
        arr[i] *= arr[i]; 
    }

    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
