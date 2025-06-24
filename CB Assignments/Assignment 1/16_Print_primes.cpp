#include <iostream>
using namespace std;

int main() {
    int n;
    cin>> n;
	if (n < 1 || n > 1000) return 0;

    for (int i = 2; i <= n; i++) {
        int isPrime = 1;
        for (int j = 2; j*j <= i; j++) {
            if (i%j == 0) { 
                isPrime = 0;
                break;
            }
        }
        if(isPrime) {
            cout<< i <<endl;
        }
    }
    return 0;
}