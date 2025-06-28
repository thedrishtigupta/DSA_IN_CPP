#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin>>n;

    int* arr = new int[n];
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    int q;
    cin>>q;

    int x;

    for (int i = 0; i < q; i++) {
        cin>>x;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int ans = pow(2, q) * sum;

    cout<<ans % (1000000000 + 7)<<endl;
    return 0;
}