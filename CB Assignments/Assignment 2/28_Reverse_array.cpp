#include<iostream>
#include<algorithm>
using namespace std;
void reverse(int arr[], int n) {
	for (int i = 0; i < n/2; i++) {
		swap(arr[i], arr[n-i-1]);
	}
}
int main() {
	int n;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	reverse(arr, n);
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<endl;
	}

	delete[] arr;
	return 0;
}