#include <iostream>
#include <array>
#include <utility>
using namespace std;
void reverseArr(int a[], int n) {
    int i = 0, j = n-1;
    while (i<j) {
        swap(a[i++], a[j--]);
    }
}
void reverseArrRecursive(int a[], int i, int j) {
    if (i < j) {
        swap(a[i], a[j]);
        reverseArrRecursive(a, i+1, j-1);
    }
}
void reverseArrRec(int a[], int n) {
    if (n <= 1) return;

    swap(a[0], a[n-1]);
    reverseArrRec(a+1, n-2);
}
int main() {
    
    int a[5] = {4,2,1,5,3};
    cout<<"No reverse: \t";
    for (int i = 0; i <5; i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;

    cout<<"Reverse: \t";
    // for (int i = 0; i < 5/2; i++) {
    //     int temp = a[i];
    //     a[i] = a[5-i-1];
    //     a[5-i-1] = temp;
    // }
    reverseArrRec(a, 5);

    for (int i = 0; i <5; i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;


    return 0;
}