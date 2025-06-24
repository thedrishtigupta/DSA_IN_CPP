#include<iostream>
using namespace std;
int factorial (int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
int main() {
	int n;
	cin>>n;

	if (n < 0 || n > 100) return 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				cout <<1<<"\t";
			} else {
				int val = factorial(i) / (factorial(j) * (factorial(i-j)));
				cout<<val<<"\t";
			}
		}
		cout<<endl;
	}
	return 0;
}