#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int primal(int arr[], int n) {
    int m = 2*n-1;
    int* newArr = new int[m];
    for (int i = 0; i < m; i++) {
        newArr[i] = arr[i%n];
    }

    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < m; i++) {
        currSum += newArr[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }

    delete[] newArr;
    return maxSum;
}


int max_kadane(int arr[], int n) {
    int currSum = arr[0], maxSum = arr[0];
    for (int i = 1; i < n; i++) {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}
int min_kadane(int arr[], int n) {
    int currSum = arr[0], minSum = arr[0];
    for (int i = 1; i < n; i++) {
        currSum = min(arr[i], currSum + arr[i]);
        minSum = min(minSum, currSum);
    }
    return minSum;
}
int optimal (int arr[], int n) {
    int maxKadane = max_kadane(arr, n);
    int minKadane = min_kadane(arr, n);

    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    if (maxKadane < 0) return maxKadane;

    return max(maxKadane, totalSum - minKadane);
}
int main() {
    int t;
	cin>>t;
	if (t < 1 || t > 100) return 0;
    while (t--) {
        int n;
        cin>>n;
        if (n < 1 || n > 1000) return 0;

        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
            if (arr[i] > 10000) return 0;
        }

        cout<<optimal(arr, n)<<endl;


        delete[] arr;
    }
    
    return 0;
}