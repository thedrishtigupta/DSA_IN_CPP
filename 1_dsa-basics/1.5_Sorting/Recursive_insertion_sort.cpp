#include <iostream>
using namespace std;
// void insert(int *a, int curr, int prev) {
//     if(prev < 0 || a[prev] <= curr) return;

//     a[prev+1] = a[prev];

// }
void Recursive_insertion_sort(int arr[], int n) {
    if (n <= 1) return;

    Recursive_insertion_sort(arr, n-1);

    int curr = arr[n-1];
    int prev = n - 2;
    while (prev >= 0 && arr[prev] > curr) {
        arr[prev+1] = arr[prev];
        prev--;
    }
    arr[prev+1] = curr;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout<< arr[i] <<"\t";
    }
    cout<<endl;
}

int main() {
    int arr[] = {9,3,7,5,6,4,8,2};
    int n = sizeof(arr)/ sizeof(arr[0]);

    printArr(arr, n);
    Recursive_insertion_sort(arr, n);
    printArr(arr,n);
    return 0;
}