#include<iostream>
using namespace std;
int main() {
	int n;
	cin >>n;

	if (n < 0 || n > 10) return 0;

	for (int i = 1; i<= n; i++) {
		int num = i;
		for (int space = 1; space <= n-i; space++) {
			cout<<" \t";
		}
		for (int j = 1; j<= 2*i-1; j++) {
			cout<<num<<"\t";
			(j > (2*i-1)/2) ? num-- : num++;
		}
		cout<<endl;
	}
	return 0;
}