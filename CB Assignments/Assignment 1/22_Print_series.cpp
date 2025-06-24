#include<iostream>
using namespace std;

void printSeries (int N1, int N2) {
	for (int i = 1; i <= N1; i++) {
		int ans = 3*i +2;
		if (ans % N2 == 0) N1++;
		else {
			cout<<ans<<endl;
		}
	}
}
int main() {
	int N1, N2;
	cin>>N1>>N2;

	if (N1 < 0 || N1 > 100 || N2 < 0 || N2 > 100) return 0;

	printSeries(N1, N2);
	return 0;
}