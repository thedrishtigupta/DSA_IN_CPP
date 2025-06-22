#include <iostream>
using namespace std;

void Inplace_merge(int arr[], int start, int mid, int end) { // not preferred, T.C. O(n^2), S.C. O(1)
    int i = start, j = mid+1;

    if (arr[mid] <= arr[j]) return; // edge case

    while (i <= mid && j <= end) {
        if (arr[i] > arr[j]) {
            int temp = arr[j];
            int index = j;

            while (index > i) {
                arr[index] = arr[index-1];
                index--;
            }
            arr[i] = temp;
            i++; j++; mid++;
        } else i++;
    }
}
void Merge(int arr[], int start, int end) { //T.C. O(nlogn), S.C. O(n)

    int mid = start + ((end-start)/2);

    int m = mid - start + 1, n = end - mid;

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
    Inplace_merge(arr, start, mid, end);

}

void print_array(int arr[], int n) {
    for (int i = 0; i < n ; i++) {
        cout<<arr[i]<<"\t";
    } cout<<endl;
}

int main() {
    int arr[100];

    int n;
    cout<<"Enter size of array: ";
    cin>> n;

    cout<<"Enter elements of array: ";
    for (int i = 0; i < n ; i++) {
        cin>> arr[i];
    }

    print_array(arr, n);

    MergeSort(arr, 0, n-1);

    print_array(arr, n);
    return 0;
}