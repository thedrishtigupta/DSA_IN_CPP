#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	if (n < 2 || n > 1000000000) return 0;

	int isPrime = 1;

	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			isPrime = 0;
			break;
		}
	}
	if (isPrime) {
		cout<<"Prime";
	} else {
		cout<<"Not Prime";
	}
	return 0;
}