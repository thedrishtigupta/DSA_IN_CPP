

class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;

        if(t[i] != -1) return t[i];

        int op1 = nums[i] + solve(nums, i+2);
        int op2 = solve(nums, i+1);

        return t[i] = max(op1, op2);
    }
    int rob(vector<int>& nums) {

        memset(t, -1, sizeof(t));
        return solve(nums, 0);
    }
};


// Bottom up
/*
steal = nums[i-1] + t[i-2]
skip = t[i-1]
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n+1, 0);

        t[1] = nums[0];

        for(int i = 2; i <= n; i++) {
            t[i] = max(nums[i-1] + t[i-2], t[i-1]);
        }

        return t[n];
    }
};

//Constant space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int minus2 = 0, minus1 = nums[0];
        int ans = nums[0];

        for(int i = 2; i <= n; i++) {
            ans = max(nums[i-1] + minus2, minus1);
            minus2 = minus1;
            minus1 = ans;
        }

        return ans;
    }
};