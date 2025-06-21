#include <iostream>
using namespace std;

void Merge(int arr[], int start, int end) {

    int mid = start + ((end-start)/2);

    int m = mid - start + 1, n = end - mid;

    //Creating 2 temp arrays
    int *A = new int[m];
    int *B = new int[n];

    int k = start;
    for (int i = 0; i < m; i++) {
        A[i] = arr[k++];
    }

    k = mid+1;
    for (int i = 0; i < n; i++) {
        B[i] = arr[k++];
    }

    int i = 0, j = 0;
    k = start;

    while (i < m && j < n) {
        if (A[i] < B[j]) arr[k++] = A[i++];
            else arr[k++] = B[j++];
    }

    while (i < m) arr[k++] = A[i++];
    while (j < n) arr[k++] = B[j++];

    delete []A;
    delete []B;
}

void MergeSort(int arr[], int start, int end) {
    if (start >= end) return;

    int mid = start + ((end-start)/2);

    MergeSort(arr,start, mid);
    MergeSort(arr,mid+1, end);
    Merge(arr, start, end);

}
int main() {
    int arr[8] = {9,3,7,5,6,4,8,2};
    int n = 8;

    MergeSort(arr, 0, 7);

    for (int i = 0; i < n; i++) {
        cout<<arr[i] <<"\t";
    }
    cout<<endl;
    return 0;
}