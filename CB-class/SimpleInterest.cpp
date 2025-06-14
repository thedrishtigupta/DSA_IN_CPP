#include <iostream>
using namespace std;

int main() {
    int P, R, T;
    cout<<"Enter P, R, T: ";
    cin >> P>> R >> T;
    
    float SI = (P*R*T) / 100.0;
    cout<<"SI= "<<SI<<endl;

    return 0;
}