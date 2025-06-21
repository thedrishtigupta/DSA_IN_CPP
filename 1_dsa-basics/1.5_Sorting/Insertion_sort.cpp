#include <iostream>
#include <utility>
using namespace std;

void insertion_sort(int arr[], int n) {

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    insertion_sort(arr, n);
    print_array(arr, n);


    return 0;
}