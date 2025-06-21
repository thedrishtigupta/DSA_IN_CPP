#include <iostream>
using namespace std;

void selection_sort(int arr[], int n) {

    for(int i = 0; i < n-1; i++) {
        int small = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[small]) {
                small = j;
            }
        }
        swap (arr[i], arr[small]);
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
    selection_sort(arr, n);
    print_array(arr, n);
    return 0;
}