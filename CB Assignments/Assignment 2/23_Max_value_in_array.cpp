#include<iostream>
#include<climits>
using namespace std;
int largest(int arr[], int n) {
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
int main() {
	int n;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	int large = largest(arr, n);
	cout<<large;

	delete[] arr;
	return 0;
}