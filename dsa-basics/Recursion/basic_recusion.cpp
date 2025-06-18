#include <iostream>
#include <string>
#include<utility>
using namespace std;
void printHello(int n) {
    if (n == 0) {
        return;
    }
    cout<<"Hello!"<<endl;
    printHello(n-1);
}
void printNum(int i, int n) {
    if (i > n) {
        return;
    }
    cout<<i <<"\t";
    printNum(i+1, n);
}
void printNumReverse(int n) {
    if (n == 0) {
        return;
    }
    cout<<n <<"\t";
    printNumReverse(n-1);
}
int sumN(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumN(n-1);
}
int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
void reverseArray(int a[], int start, int end) {
    if (start < end) {
        swap(a[start], a[end-1]);
        reverseArray(a, start+1, end-2);
    }
}
void reverseArray(int a[], int n) {
    if (n <= 1) return;

    swap(a[0], a[n-1]);
    reverseArray(a+1, n-2);
}

int main() {

    int n;
    cout<<"Enter n: ";
    cin>> n;

    //printHello(n);
    // printNum(1, n);
    // cout<<endl;
    // printNumReverse(n);
    //cout<<"Sum of first "<<n<<" numbers = "<<sumN(n)<<endl;
    //cout<<"Factorial of "<<n<<" = "<<factorial(n)<<endl;
    //cout<<"Fibonacci of "<<n<<" = "<<fibonacci(n)<<endl;
    
    int arr[20];
    cout<<"Enter elements of array: ";
    for (int i = 0; i <n; i++) {
        cin>>arr[i];
    }

    reverseArray(arr, n);

    for (int i = 0; i <n; i++) {
        cout<<arr[i]<<"\t";
    }




    return 0;
}