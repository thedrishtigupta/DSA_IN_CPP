#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    unordered_map<int, int> mp;

    for (int i = 0; i < sorted.size(); i++) {
        if (mp.find(sorted[i]) == mp.end()) {
            mp[sorted[i]] = i;
        }
    }

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        result.push_back(mp[nums[i]]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> res = smallerNumbersThanCurrent(arr);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
