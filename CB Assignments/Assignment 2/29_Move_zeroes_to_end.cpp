#include<iostream>
using namespace std;

int main () {
	int n;
	cin>>n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	int i = 0, j = n-1;
	while (i < j) {
		if (arr[j] == 0) j--;
		if (arr[i] == 0) {
			int index = i;
			while (index < j) {
				arr[index] = arr[index+1];
				index++;
			}
			arr[j] = 0;
			j--;
		} else i++;
	}

	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	delete[] arr;
	return 0;
}