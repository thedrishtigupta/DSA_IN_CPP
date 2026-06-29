
//Recursion + memoization
class Solution {
public:
    long long t[1000001][2];
    long long solve(vector<int>& nums, int i, bool flag, int& n) {
        if(i >= n) return 0;

        if(t[i][flag] != -1) return t[i][flag];
        long long op1, op2;
        if(!flag) op1 = nums[i] + solve(nums, i+1, !flag, n);
        else op1 = -nums[i] + solve(nums, i+1, !flag, n);

        op2 = solve(nums, i+1, flag, n);

        return t[i][flag] = max(op1, op2);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        memset(t, -1, sizeof(t));

        return solve(nums, 0, false, n);
    }
};