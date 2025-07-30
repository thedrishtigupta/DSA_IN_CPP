#include <iostream>
using namespace std;

bool check7(int* a, int n, int i = 0) {
    if (n == 0) return false;

    if (a[i] == 7) return true;
    else check7(a, n, i+1);

    return true;
}
int main() {
    int arr[]= {1,2,4,3};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<<check7(arr, n);
    return 0;
}