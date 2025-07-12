#include <iostream>
#include <vector>
using namespace std;
vector<int> optimal(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);

    int j = 0, k = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            ans[k] = nums[i];
            k += 2;
        } else {
            ans[j] = nums[i];
            j += 2;
        }
    }
    return ans;
}
void print(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<"\t";
    }
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    print(optimal(nums));

    return 0;
}