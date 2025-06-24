#include <iostream>
using namespace std;
#include<math.h>
#define limit pow(10, 18)
long long reverse(long long num) {
    long long reverse = 0;
    while (num > 0) {
        reverse = (reverse*10) + (num % 10);
        num /= 10;
    }
    return reverse;
}
// void print(int arr[], int n) {
//     for (int i = 0; i< n; i++) {
//         cout<<arr[i]<<endl;
//     }
// }
int main() {
    int n;
	cin>> n;
    // int* arr = new int[n];

	if (n > 10000 || n < 1) return 0;
	for (int i = 0; i <n; i++) {
		long long a, b;
    	cin>>a>>b;

		if ((a < 1 || a > limit) || (b < 1 || b > limit)) return 0;
		long long sum = reverse(a) + reverse(b);
        // arr[i] = reverse(sum);
		cout <<reverse(sum)<<endl;
	}
    // print(arr, n);
	
    return 0;
}