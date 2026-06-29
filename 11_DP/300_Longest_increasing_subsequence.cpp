

//Recursion + memoization
class Solution {
public:
    int t[2501][2502];
    int solve(vector<int>& nums, int& n, int i, int prev) {
        if(i >= n) return 0;

        if(t[i][prev+1] != -1) return t[i][prev+1];
        int op1 = 0;
        if (prev == -1 || nums[i] > nums[prev]) op1 = 1 + solve(nums, n, i+1, i);

        int op2 = solve(nums, n, i+1, prev);

        return t[i][prev+1] = max(op1, op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        memset(t, -1, sizeof(t));
        return solve(nums, n, 0, -1);
    }
};

//Bottom up
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);

        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j]+1);
                }
            }
            ans = max(ans, t[i]);
        }

        return ans;
    }
};