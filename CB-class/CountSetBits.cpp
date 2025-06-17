#include <iostream>
using namespace std;

int main() {
    // set bits are 1s'

    int num,orgNum, count = 0;
    cout<<"Enter number: ";
    cin>>num;
    orgNum = num;

    // Division method
    // while (num > 0) {
    //     if (num % 2 != 0) count++;
    //     num /= 2;
    // }

    // Using Left shift operator
    while (num > 0) {
        if ((num & 1) == 1) count++;
        num = num >> 1;
    }
    cout<<"Set bits in "<<orgNum <<" is: "<<count<<endl;

    return 0;
}