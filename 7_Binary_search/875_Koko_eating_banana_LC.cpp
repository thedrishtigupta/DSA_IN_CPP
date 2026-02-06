/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of
bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all
of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the
guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.


Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
*/


class Solution {
public:
    bool canEat(vector<int>& p, int k, int h) {
        long long ans = 0;
        for (int val : p) ans += (1LL * val + k - 1) / k;
        return ans <= h;
    }

    int minEatingSpeed(vector<int>& p, int h) {
        int i = 1, j = *max_element(p.begin(), p.end());
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (canEat(p, m, h)) j = m - 1;
            else i = m + 1;
        }
        return i;
    }
};
