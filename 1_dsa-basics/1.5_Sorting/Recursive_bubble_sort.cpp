#include <iostream>
#include <utility>
using namespace std;
void swapping(int *a, int n, int j = 0) {
    if (j == n-1) return;

    if (a[j] > a[j+1]) swap(a[j], a[j+1]);
    swapping(a, n, j+1);
}
void Recursive_Bubble_Sort(int arr[], int n) {
    if (n == 1) return;
    // for (int j = 0; j < n-1; j++) {
    //     if (arr[j] > arr[j+1]) {
    //         swap(arr[j], arr[j+1]);
    //     }
    // }
    swapping(arr, n);
    Recursive_Bubble_Sort(arr, n-1);
}
void Bubble_Sort(int a[], int n, int i = 0, int j = 0) {
    if (i == n-1) return;
    
    if (j < n-i-1) {
        if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        Bubble_Sort(a, n, i, j+1);
    } else Bubble_Sort(a, n, i+1, 0);
}
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout<< arr[i] <<"\t";
    }
    cout<<endl;
}
int main() {
    int arr[] = {4, 3, 2, 1, 5};
    int n = 5;
    printArr(arr, n);
    Bubble_Sort(arr, n);
    printArr(arr, n);
    return 0;
}