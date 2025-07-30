#include <iostream>
using namespace std;
void printInc(int n) {
    if (n == 0) return;

    printInc(n-1);
    cout<<n<<'\t';
}
void printDec(int n) {
    if (n == 0) return;

    cout<<n<<'\t';
    printDec(n-1);
}
int main() {
    int n = 5;
    printInc(n);
    cout<<endl;
    printDec(n);
    return 0;
}