#include <iostream>
#include <climits>
using namespace std;

int main() {
    
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[100];
    int max1 = INT_MIN+1, max2 = INT_MIN;

    cout<<"Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }

    cout<<"Largest element is : "<<max1<<" and Second largest element is: "<<max2<<endl;
    return 0;
}