#include <iostream>
//#include <vector>
#include <algorithm>
using namespace std;
void optimal(int arr[], int n, int target) {
    sort(arr, arr+n);
    //vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        int j = i+1, k = n-1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum > target) k--;
            else if (sum < target) j++;
            else {
                //v.emplace_back(arr[i], arr[j], arr[k]);
                cout<<arr[i] <<", "<<arr[j] <<" and "<<arr[k] <<endl;
                j++; k--;
            }
        }
    }
}
int main() {
    int n;
    cin>>n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int target;
    cin>>target;

    optimal(arr, n, target);


    delete[] arr;
    return 0;
}