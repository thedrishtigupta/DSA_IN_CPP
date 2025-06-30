#include <iostream>
#include <algorithm>
using namespace std;
int optimal(int a[], int b[], int n, int m) {
    int sumA = 0, sumB = 0, ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            sumB += b[j++];
        } else if (a[i] < b[j]) {
            sumA += a[i++];
        } else {
            ans += max(sumA, sumB) + a[i];
            sumA = 0, sumB = 0;
            i++; j++;
        }
    }
    while (i < n) sumA += a[i++];
    while (j < m) sumB += b[j++];

    ans += max(sumA, sumB);
    return ans;
}
int main() {
    int t;
    cin>>t;

    while (t--) {
        int n, m;
        cin>>n>>m;

        int* a = new int[n];
        int* b = new int[m];
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        for (int i = 0; i < m; i++) {
            cin>>b[i];
        }
        

        cout<<optimal(a, b, n, m)<<endl;


        delete[] a;
        delete[] b;
    }
    return 0;
}