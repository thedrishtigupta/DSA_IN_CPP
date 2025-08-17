#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;

        for(int mask=0; mask < (1<<n); mask++){
            vector<int> temp;
            for(int i=0; i<n; i++){
                if((1<<i)&mask) temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

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