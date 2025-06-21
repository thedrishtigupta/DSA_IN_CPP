#include <iostream>
using namespace std;

int main() {
    int num;
    cout<<"Enter a number: ";
    cin >> num;
    // int isPrime = 1;

    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            // isPrime = 0;
            cout<<"NOT prime"<<endl;
            return 0;
        }
    }
    cout<<"Prime"<<endl;
    // isPrime ? cout<<"Prime"<<endl : cout<<"NOT prime"<<endl;
    return 0;
}