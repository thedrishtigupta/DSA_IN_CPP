/*
There is an integer array nums sorted in non-decreasing order
(not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index
k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1],
nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be
rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if
target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.


Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
*/

class Solution {
public:
    bool search(vector<int>& a, int x) {
        int i = 0, j = a.size()-1;

        while (i <= j) {
            int m = i + ((j-i)/2);

            if (a[m] == x) return true;

            if (a[i] == a[m] && a[m] == a[j]) {i++; j--; continue;}

            if (a[i] <= a[m]) {
                if (a[i] <= x && x <= a[m]) j = m-1;
                else i = m+1;
            } else {
                if (a[m] <= x && x <= a[j]) i = m+1;
                else j = m-1;
            }
        }
        return false;
    }
};