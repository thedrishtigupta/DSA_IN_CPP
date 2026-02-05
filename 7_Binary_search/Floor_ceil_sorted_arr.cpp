#include <iostream>
#include <vector>
using namespace std;
vector<int> floor_ceil(vector<int>& arr, int x) {
    int n = arr.size();

    int i = 0, j = n-1;
    vector<int> ans(2, -1);

    while (i <= j) {
        int m = i + ((j-i)/2);
        if (arr[m] == x) return {x, x};
        else if (arr[m] > x) {
            ans[1] = arr[m];
            j = m-1;
        } else {
            ans[0] = arr[m];
            i = m+1;
        }
    }
    return ans;
}

void print(vector<int> arr) {
    for (int val : arr) cout<<val<<"\t";
    cout<<endl;
}
int main() {
    vector<int> arr = {1, 3, 5, 7, 8, 10};
    int x;
    cin>>x;

    print(floor_ceil(arr, x));
    return 0;
}