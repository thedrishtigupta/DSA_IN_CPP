#include <iostream>
using namespace std;
bool isPrime(int num, int j = 2) {

    if (num <= 1) return false; // edge case

    if (j*j > num) return true; // base case
    else if (num % j == 0) return false;

    return isPrime(num, j+1);
}
void range(int b, int a = 2) {
    if (a > b) return;

    if (isPrime(a)) cout<<a<<"\t";
    range(b, a+1);
}
int main() {
    int num = 10;
    range(num, 1);
    return 0;
}