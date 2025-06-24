#include<iostream>
#include<climits>
using namespace std;
int main () {

	int arr[5];
	int large = INT_MIN;
	for (int i = 0; i < 5; i++) {
		cin>>arr[i];
		if (arr[i] > large) large = arr[i];
	}
	cout<<large;

	return 0;
}