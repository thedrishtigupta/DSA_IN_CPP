/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n1 = A.size(), n2 = B.size();
        if (n1 > n2) return findMedianSortedArrays(B, A);

        int total = n1 + n2;
        int i = 0, j = n1;
        int left = (total + 1)/2;

        while(i <= j) {
            int m1 = (i+j) >> 1;
            int m2 = left - m1;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if(m1 < n1) r1 = A[m1];
            if(m2 < n2) r2 = B[m2];

            if(m1 - 1 >= 0) l1 = A[m1 - 1];
            if (m2 -1 >= 0) l2 = B[m2 - 1];

            if(l1 <= r2 && l2 <= r1) {
                if (total % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;
                else return max(l1, l2);
            } else if (l1 > r2) j = m1-1;
            else i = m1 + 1;
        }
        return 0;
    }

};