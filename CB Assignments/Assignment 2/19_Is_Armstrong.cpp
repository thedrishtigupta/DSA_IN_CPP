#include<iostream>
#include <math.h>
using namespace std;
bool checkArmstrong(int n){
	int k = (int)(log10(n) + 1); // for count digits
	int num = n, answer = 0;
	while (n > 0) {
		answer += pow((n % 10),k);
		n /= 10;
	}
	return num == answer ? true : false;
}
int main() {
	int n;
	cin>>n;

	if ( n < 0 || n > 1000000000) return 0;

	if (checkArmstrong(n)) cout<<"true";
	else cout<<"false";
	return 0;
}