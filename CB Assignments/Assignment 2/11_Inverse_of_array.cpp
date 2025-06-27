#include<iostream>
using namespace std;
void inverse(int arr[], int inv[], int i, int n) {
	if (i == n) return;
	inv[arr[i]] = i;
	inverse(arr, inv, i+1, n);
}
int main() {
	int n;
	cin>> n;

	int* arr = new int[n];
	int *inv = new int[n];

	for (int i = 0; i <n; i++) {
		cin>>arr[i];
	}

	inverse(arr, inv, 0, n);

	for (int i = 0; i < n; i++) {
		cout<<inv[i]<<" ";
	}
	return 0;
}