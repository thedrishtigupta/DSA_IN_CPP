#include<iostream>
using namespace std;
int main () {

	int n;
	cin>>n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	int freq = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (freq == 0) ans = arr[i];

		freq += (arr[i] == ans) ? 1 : -1;
	}

	cout<<ans;
	return 0;
}