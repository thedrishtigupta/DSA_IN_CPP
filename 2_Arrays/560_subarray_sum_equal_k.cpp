#include <iostream>
#include <vector>
using namespace std;
int primal(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 1 && nums[0] != k) return 0; 
    int ans = 0, sum = 0, j = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum > k) sum -= nums[j++];
        if (sum == k || nums[i] == k) ans++;
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