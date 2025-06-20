#include <iostream>
#include <utility>
using namespace std;

int Partition(int arr[], int start, int end) {
    int pivot = arr[start], count=0;

    for (int i = start+1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = start + count;
    swap (arr[pivotIndex], arr[start]);


    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j) {
            swap(arr[i++], arr[j--]);
        }
    }
    return j;
}

void Quick_sort(int arr[], int start, int end) {
    if (start >= end) return;
    int j = Partition(arr, start, end);
    Quick_sort(arr, start, j-1);
    Quick_sort(arr, j+1, end);
}
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout<< arr[i] <<"\t";
    }
    cout<<endl;
}
int main() {
    int arr[8] = {9,3,7,5,6,4,8,2};
    int n = 8;
    printArr(arr, n);
    Quick_sort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}