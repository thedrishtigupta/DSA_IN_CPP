#include <iostream>
#include <unordered_map>
#include <array>
#include <climits>
using namespace std;

/* Find the maximum occur element in array, if freq of 2 elements is same, return the element on lowest index*/

int main() {
    
    array<int,5> arr = {1, 2, 3, 1 ,2};

    unordered_map<int, int> count;

    int freq = INT_MIN, ans = -1;

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
        freq = max(freq, count[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++) {
        if (freq == count[arr[i]]) {
            ans = arr[i];
            break;
        }
    }

    cout<<ans<<endl;

    return 0;
}