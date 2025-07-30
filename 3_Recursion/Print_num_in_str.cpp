#include <iostream>
#include <string>
using namespace std;
string keys[10] {
    "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
};
void print(int num) {
    if (num <= 0) return;
    int val = num % 10;
    print(num/10);
    cout<<keys[val]<<" ";
}
int main() {
    int num = 2048;
    print(num);
    return 0;
}