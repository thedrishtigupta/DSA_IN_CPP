#include <iostream>
#include <climits>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}
bool isPrime (int n) {
    for (int i = 2; i*i <=n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cin>>num;

	if (num < 1 || num > INT_MAX) return 0;
    int orgNum = num;
    int sumPrimes = 0;
    for (int i = 2; i*i <= orgNum; i++) {
		while (num % i == 0 && num > 0) {
			sumPrimes += sumOfDigits(i);
			num /= i;
        }
    }
    if (num > 1) {
        sumPrimes += sumOfDigits(num);
    }
    int sumDigits = sumOfDigits(orgNum);

    if (sumPrimes == sumDigits) cout<<1;
    else cout << 0;
    return 0;
}