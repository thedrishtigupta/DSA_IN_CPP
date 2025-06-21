#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    // max heap
    priority_queue<int> maxi;

    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    while (maxi.size() != 0) {
        cout<< maxi.top()<<"\t";
        maxi.pop();
    }
    cout<<endl;

    mini.push(2);
    mini.push(1);
    mini.push(0);
    mini.push(3);

    while(mini.size() != 0) {
        cout<< mini.top()<<"\t";
        mini.pop();
    }

    return 0;
}