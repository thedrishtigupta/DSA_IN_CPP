#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    if (n < 0 || n > 100) return 0;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        if (arr[i] < 0 || arr[i] > 50) return 0;
    }

    int target;
    cin>>target;
    
    if (target < 0 || target > 100) return 0;

    int i = 0, j = n-1;

    while (i <= j) {
        if (arr[i] == target) {
            int index = i;
            while (index < j) {
                arr[index] = arr[index+1];
                index++;
            }
            j--;
        } else i++;
        if (arr[j] == target) j--;
    }

    for (int k = 0; k  <= j; k++) {
        cout<<arr[k]<<" ";
    }
}