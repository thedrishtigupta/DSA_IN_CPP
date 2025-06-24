#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;

	if (n < 1 || n >= 10) return 0;

	for (int i = 1; i <= n; i++) {
		int num = 1;
		for (int j = 1; j <= i; j++) {
			cout<<num++;
		}
		for (int star = 1; star <= n-i; star++) {
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}