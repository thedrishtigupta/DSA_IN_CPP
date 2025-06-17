#include <iostream>
#include <climits>
using namespace std;

int main() {
    
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[100];
    int max = INT_MIN;

    cout<<"Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > max) max = arr[i];
    }

    cout<<"Largest element is: "<<max<<endl;
    return 0;
}