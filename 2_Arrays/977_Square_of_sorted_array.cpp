#include <iostream>
#include <vector>
using namespace std;
vector<int> optimal(vector<int> a) {
    int n = a.size();
    vector<int>ans(n);
    int i = 0, j = n-1, k = n-1;
    while (i <= j) {
        int x = a[i]*a[i], y = a[j]*a[j];
        if (x > y) {
            ans[k--] = x; i++;
        } else {
            ans[k--] = y; j--;
        }
    }
    return ans;
}
void print(vector<int> a, int n){
    for (int i = 0; i <n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    print(optimal(a), n);
    return 0;
}