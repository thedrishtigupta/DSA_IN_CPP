#include <iostream>
#include <vector>
using namespace std;

void printSub(vector<int>& arr, vector<int>& ans, int n, int i = 0) {
    if (i == n) {
        for (int val : ans) cout<<val<<" ";
        cout<<endl;
        return;
    }

    // inclusion
    ans.push_back(arr[i]);
    printSub(arr, ans, n, i+1);

    //exclusion
    ans.pop_back(); // backtracking
    printSub(arr, ans, n, i+1);
}

void printOp (vector<int>& arr, vector<int>& ans, int n, int i = 0) {
    if (i == n) {
        if (ans.empty()) cout<<"[]";
        else {
            for (int val : ans) cout<<val<<" ";
        }
        cout<<endl;
        return;
    }

    printOp(arr, ans, n, i+1);

    ans.push_back(arr[i]);
    printOp(arr, ans, n, i+1);

    ans.pop_back();
}
int main() {
    vector<int> arr = {1,2,3};
    vector<int> ans;
    printOp(arr, ans, arr.size());
    return 0;
}