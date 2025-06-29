#include <iostream>
#include <vector>
using namespace std;
vector<int> primal(vector<int> nums) {
    int n = nums.size();
    vector<int> ans(n,1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ans[i] *= nums[j];
            }
        }
    }
    return ans;
}

vector<int> better (vector<int> nums) {
    int n = nums.size();
    vector<int> ans(n,1);

    vector<int> prefix(n,1);
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    vector<int> suffix(n,1);
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    
    for (int i = 0; i < n; i++) {
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}
vector<int> optimal (vector<int> nums) {
    int n = nums.size();
    vector<int> ans(n,1);

    for (int i = 1; i < n; i++) {
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffix = 1;
    for (int i = n-2; i >= 0; i--) {
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }

    return ans;
}
void print(vector<int> nums, int n) {
    for (int i = 0; i < n; i++) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
}
int main() {
    int n; cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    print(optimal(nums), n);

    return 0;
}