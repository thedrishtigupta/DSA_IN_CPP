#include <iostream>
using namespace std;

int replace(int num) {
    int result = 0, place = 1;

    while (num > 0) {
        int digit = num % 10;
        if (digit == 0) digit = 5; 
        result += digit * place;
        place *= 10;
        num /= 10;
    }

    return result;
}

int main () {
    int num;
    cin >> num;
    
    cout << replace(num);

    return 0;
}
