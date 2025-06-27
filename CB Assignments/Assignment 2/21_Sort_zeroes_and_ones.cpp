#include<iostream>
#include<algorithm>
using namespace std;

void replace(int arr[], int n) {
	int i = 0, j = n-1;

	while (i < j) {
		if (arr[j] == 1) j--;
		if (arr[i] == 1) {
			swap(arr[i], arr[j]);
			j--;
		} else i++;
	}
}
int main() {
	int n;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	replace(arr, n);

	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	

	delete[] arr;
	return 0;
}