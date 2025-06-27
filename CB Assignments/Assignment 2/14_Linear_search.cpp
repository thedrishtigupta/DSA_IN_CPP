#include<iostream>
using namespace std;
int linearSearch(int arr[], int n, int num) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == num) return i;
	}
	return -1;
}
int main() {
	int n;
	cin>>n;
	if (n < 0) return 0;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin>>arr[i];
		if (arr[i] < -1000000000 || arr[i] > 1000000000) return 0;
	}
	int num;
	cin>>num;
	if (num < -1000000000 || num > 1000000000) return 0;
	int index = linearSearch(arr, n, num);

	if (index == -1) {
		cout<<-1;
	} else cout<<index;

	delete[] arr;
	return 0;
}