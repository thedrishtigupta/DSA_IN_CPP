#include <iostream>
using namespace std;
void check(int arr[], int n) {
    int price; cin>>price;
    int k; cin>>k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (price % arr[i] == 0) ans++;
    }
    if (k <= ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main() {
    int n;
    cin>>n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int q;
    cin>>q;
    while (q--) {
        check(arr, n);
    }
    return 0;
}