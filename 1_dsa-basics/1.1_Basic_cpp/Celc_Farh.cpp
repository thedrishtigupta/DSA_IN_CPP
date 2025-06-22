#include <iostream>
using namespace std;

void printCelsius(int start, int end, int step) {
    cout<<"°F\t°C"<<endl;

    for (int i = start; i <= end; i+=step) {
        cout<<i<<"\t"<<(5.0/9.0)*(i-32)<<endl;
    }
}
int main() {
    
    int start, end, step;

    cout<<"Enter initial value: ";
    cin>>start;
    cout<<"Enter final value: ";
    cin>>end;
    cout<<"Enter step value: ";
    cin>>step;

    printCelsius(start, end, step);
    
    return 0;
}