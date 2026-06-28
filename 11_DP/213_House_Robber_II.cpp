
/*
Only need to take care of 0th index for circular array.
*/
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n) {
        if (i >= n) return 0;

        if(t[i] != -1) return t[i];

        int op1 = nums[i] + solve(nums, i+2, n);
        int op2 = solve(nums, i+1, n);

        return t[i] = max(op1, op2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        memset(t, -1, sizeof(t));
        int op1 = solve(nums, 0, n-1);
        memset(t, -1, sizeof(t));
        int op2 = solve(nums, 1, n);

        return max(op1, op2);
    }
};