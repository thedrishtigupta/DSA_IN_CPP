#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the end range: ";
    cin>> n;
    for (int i = 2; i <= n; i++) {
        int isPrime = 1;
        for (int j = 2; j*j <= i; j++) {
            if (i%j == 0) { //bade number ko chote number se divide krte h, not the other way around!
                isPrime = 0;
                break;
            }
        }
        if(isPrime) {
            cout<< i <<" ";
        }
    }
    return 0;
}