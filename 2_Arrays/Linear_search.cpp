#include <iostream>
using namespace std;
int Linear_search(int arr[], int n, int key) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }
    return index;
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

    int key;
    cout<<"Enter element to search for: ";
    cin >> key;

    int index = Linear_search(arr, n, key);

    if (index == -1) cout<<"Element not found";
        else cout<<"Element found at index "<<index<<endl;

    return 0;
}