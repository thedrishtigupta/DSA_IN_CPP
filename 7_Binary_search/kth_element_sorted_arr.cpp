
#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int findKth(vector<int>& A, vector<int>& B, int k) {
    int n1 = A.size(), n2 = B.size();
    if (n1 > n2) return findKth(B, A, k);

    //int i = 0, j = n1;

    int i = max(0, k - n2);
    int j = min(k, n1);
    
    while(i <= j) {
        int m1 = (i+j) >> 1;
        int m2 = k - m1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if(m1 < n1) r1 = A[m1];
        if(m2 < n2) r2 = B[m2];
        if(m1 - 1 >= 0) l1 = A[m1 - 1];
        if(m2 - 1 >= 0) l2 = B[m2 - 1];

        if (l1 <= r2 && l2 <= r1) return max(l1, l2);
        else if (l1 > r2) j = m1 - 1;
        else i = m1 + 1;
    }
    return -1;
}
int main() {
    vector<int> A = {100, 112, 256, 349, 770};
    vector<int> B = {72, 86, 113, 119, 264, 445, 892};
    int k = 7;

    cout<<findKth(A, B, k);
    return 0;
}