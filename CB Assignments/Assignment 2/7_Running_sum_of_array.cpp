#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;

    if (n < 1 || n > 1000) return 0;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        if (arr[i] < -1e6 || arr[i] > 1e6) return 0;
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout<<arr[i] <<" ";
            continue;
        }
        arr[i] += arr[i-1];
        cout<<arr[i]<<" ";
    }

    delete [] arr;
    return 0;

}
