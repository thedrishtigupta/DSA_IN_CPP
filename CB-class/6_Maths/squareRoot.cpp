#include <iostream>
using namespace std;

int main() {
    
    double num, inc, i;
    cout<<"Enter number: ";
    cin>>num;

    i = 0;
    inc = 1;
    for (int precision = 0; precision <= 3; i -= inc, precision++, inc /= 10) { //here precision is no. of decimal digits
        for(; i*i <= num; i += inc) {}
    }
    
    cout<<"Square root of "<<num<<" is: "<<i<<endl;
    return 0;
}