#include <iostream>
#include <utility>
using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
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
    bubble_sort(arr, n);
    print_array(arr, n);


    return 0;
}