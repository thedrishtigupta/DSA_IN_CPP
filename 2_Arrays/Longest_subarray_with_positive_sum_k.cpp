#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin>>n;

    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int k; cin>>k;

    int sum = 0, j = 0, mc = 0;
    for(int i = 0; i <n; i++) {
        sum += a[i];
        if (sum == k) {
            mc = max(mc, i-j+1);
        }
        while (sum > k) {
            sum -= a[j++];
        }
    }

    cout<<mc;
    return 0;
}