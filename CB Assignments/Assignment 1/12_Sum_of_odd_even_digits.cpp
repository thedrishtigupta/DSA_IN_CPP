#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;

	if (n < 0 || n >  1000000000) return 0;
	int sumOdd = 0, sumEven = 0, digit = 1;

	while (n > 0) {
		if (digit % 2 != 0) {
			sumOdd += n % 10;
		} else {
			sumEven += n % 10;
		}
		digit++;
		n /= 10;
	}
	cout<<sumOdd<<endl;
	cout<<sumEven<<endl;
	return 0;
}