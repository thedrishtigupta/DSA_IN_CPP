#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int count = 1;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (nums[i] == nums[j]) j++;
        else {
            nums[i+1] = nums[j];
            count++;
            i++; j++;
        }
    }
    return count;
}
int main() {
    int n;
    cin>>n;

    vector<int> nums;
    return 0;
}