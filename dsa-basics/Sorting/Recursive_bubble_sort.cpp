#include <iostream>
#include <utility>
using namespace std;

void Recursive_Bubble_Sort(int arr[], int n) {
    if (n == 1) return;
    for (int j = 0; j < n-1; j++) {
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
    Recursive_Bubble_Sort(arr, n-1);
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
    Recursive_Bubble_Sort(arr, n);
    printArr(arr, n);
    return 0;
}