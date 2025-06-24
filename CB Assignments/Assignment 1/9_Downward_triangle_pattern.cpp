#include<iostream>
using namespace std;
int main () {
	int n;
	cin>>n;

	for (int i = 1; i <= n; i++) {
		for (int space = 1; space <= i-1; space++) {
			cout<<" ";
		}
		for (int star = 1; star <= n-i+1; star++) {
			cout<<"* ";
		}
		cout<<endl;
	}
	return 0;
}