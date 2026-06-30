
/*
steps:

1. if a substring contains atleast one 'a', 'b' and 'c' (valid substring) then all its
extensions will also be valid substring.
2. suppose substring [l..r] is valid, then its extensions are
    - [l..r+1], [l..r+1] ... [l..n-1]
    - so total valid substrings are from r to n-1 i.e n-r
3. so now instead of counting all valid substrings one by one,
we find the smallest valid substring and then count all extensions of that once as n-r.
4. so to find the smallest valid substring we use sliding window(two pointers).
    - we have left and right pointer
    - we expand window until the substring is not valid
    - once we get a valid substring we add n-r to answer, then shrink the window by shifting the left pointer
    - then again we find the valid window and repeat the process.
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int p[3] = {-1, -1, -1};

        for (int i = 0; i < s.length(); i++) {
            p[(s[i] & 31) - 1] = i;
            res += min({p[0], p[1], p[2]}) + 1;
        }

        return res;
    }
};