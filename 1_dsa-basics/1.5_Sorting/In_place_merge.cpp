#include <iostream>
#include <utility>
using namespace std;



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

    int start = 0, end = n-1;
    int mid = start + ((end-start)/2);

    int i = start, j = mid+1;

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
        } else {
            i++;
        }
    }

    print_array(arr, n);



    return 0;
}