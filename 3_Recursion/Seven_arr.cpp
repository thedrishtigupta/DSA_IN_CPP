#include <iostream>
#include <vector>
using namespace std;

bool check7(int* a, int n) {
    if (n == 0) return false;

    if (a[0] == 7) return true;

    return check7(a+1, n-1);
}
int firstIdx7(int* a, int n, int i = 0) {
    if (i == n) return -1;
    if (a[i] == 7) return i;
    return firstIdx7(a, n, i+1);
}
int lastIdx7(int* a, int n) {
    if (n == 0) return -1;
    if (a[n-1] == 7) return n-1;
    return lastIdx7(a, n-1);
}
void allIdx7(int* a, int n, int i = 0) {
    if (i == n) return;

    if (a[i] == 7) cout<<i<<" ";
    allIdx7(a, n, i+1);
}
int main() {
    int arr[]= {1, 2, 7, 4, 7, 3, 7};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<<check7(arr, n)<<endl;
    cout<<"First index of 7: "<<firstIdx7(arr, n)<<endl;
    cout<<"Last index of 7: "<<lastIdx7(arr, n)<<endl;
    cout<<"All indices of 7: ";
    allIdx7(arr, n);
    return 0;
}