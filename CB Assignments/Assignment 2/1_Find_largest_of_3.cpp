#include<iostream>
#include<climits>
using namespace std;
int main() {
	int max = INT_MIN;
	for (int i = 1; i <= 3; i++) {
		int num;
		cin>> num;
		if (num > max) max = num;
	}
	cout<<max;
	return 0;
}