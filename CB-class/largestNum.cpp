#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N;
    cout<<"Enter the total numbers: ";
    cin >> N;
    int max = INT_MIN;
    cout<<"Enter numbers: "; 
    for (int i = 1; i <= N; i++) {
        int num;
        cin>>num;
        if (num > max) {
            max = num;
        }
    }
    cout << "Largest number is = "<<max<<endl;


    // // reading input until ~end-of-file~, to exit taking input -> ctrl + z + enter
    // int max = INT_MIN, num;
    // cout<<"Enter numbers: ";
    // while(cin>>num) {
    //     if (num > max) max = num;
    // }
    // cout << "Largest number is = "<<max<<endl;

    return 0;
}