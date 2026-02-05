/*
You are given a sorted array consisting of only integers where every element appears
exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.


Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int s = 0, e = arr.size()-1;

        while(s < e) {
            int m = s + ((e-s)/2);

            if((m % 2 == 0 && arr[m] == arr[m+1]) ||(m % 2 == 1 && arr[m] == arr[m-1])) s = m+1;
            else e = m;
        }
        return arr[s];
    }
};