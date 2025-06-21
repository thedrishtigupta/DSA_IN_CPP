#include <iostream>
#include<climits>
using namespace std;
int largest_num(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
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

    cout << "Largest element is: "<<largest_num(arr, n)<<endl;


    return 0;
}