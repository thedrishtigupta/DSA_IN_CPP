#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int primal(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m[0] = 1;
    int ans = 0, sum = 0;

    for (int val : nums) {
        sum ^= val;
        int rem = sum ^ k;
        if (m.find(rem) != m.end()) {
            ans += m[rem];
        }
        m[sum]++;
    }

    return ans;
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;

    cout<<primal(nums, k);



    return 0;
}