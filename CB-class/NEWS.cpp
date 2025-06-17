#include <iostream>
using namespace std;

int main() {
    char ch;
    int x = 0, y = 0;

    cout <<"Enter directions: ";
    while (cin.get(ch) && ch != '\n') {
        if (ch == 'N') y++;
        else if (ch == 'E') x++;
        else if (ch == 'W') x--;
        else if (ch == 'S') y--;
    }
    // cout <<"x = "<<x<<" , y = "<<y<<endl; // Testing

    cout<<"Shortest path is: ";
    //lexicographically -> E, N , S, W
    if (x >= 0) {
        while(x > 0) {
            cout<<"E ";
            x--;
        }
    }
    if (y >= 0) {
        while (y > 0) {
            cout<<"N ";
            y--;
        }
    } else {
        y = abs(y);
        while (y > 0) {
            cout<< "S ";
            y--;
        }
    }
    if (x < 0) {
        x = abs(x);
        while (x > 0) {
            cout<<"W ";
            x--;
        }
    }
    return 0;
}