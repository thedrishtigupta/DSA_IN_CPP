#include <iostream>
using namespace std;

int main() {
    // two pointer approach!
    int currVal = 0, val = 0;
    cout<<"Enter numbers: ";
    /* say we don't use if statement here, for first input, 
    then if there is no input and user do not give a single input,
    it will give -> 0 occurs 1 times. 
    This is not what we want, we want no execution on 0 input, that's why if*/
    if(cin>>currVal) {
        int cnt = 1;
        while (cin>>val) {
            if(currVal == val) {
                ++cnt;
            } else {
                cout<<currVal <<" occurs " <<cnt <<" times."<<endl;
                currVal = val;
                cnt = 1;
            }
        }
        cout<<currVal <<" occurs " <<cnt <<" times. "<<endl;
    }
    
    return 0;
}