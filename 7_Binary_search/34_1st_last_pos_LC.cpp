/*
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& a, int x) {
        int n = a.size();
        int i = 0, j = n-1;

        vector<int> ans(2, -1);

        while (i<=j) {
            int m = i + ((j-i)/2);
            if (x > a[m]) i = m+1;
            else if (x < a[m]) j = m-1;
            else {
                i = m, j = m;
                while (i > 0 && a[i-1] == x) i--;
                while (j < n-1 && a[j+1] == x) j++;

                ans[0] = i, ans[1] = j; return ans;
            }
        }
        return ans;
    }
};