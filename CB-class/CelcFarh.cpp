#include <iostream>
using namespace std;

int main() {
    
    int start, end, step;

    cout<<"Enter initial value: ";
    cin>>start;
    cout<<"Enter final value: ";
    cin>>end;
    cout<<"Enter step value: ";
    cin>>step;

    cout<<"°F\t°C"<<endl;

    for (int i = start; i <= end; i+=step) {
        cout<<i<<"\t"<<(5.0/9.0)*(i-32)<<endl;
    }
    
    return 0;
}