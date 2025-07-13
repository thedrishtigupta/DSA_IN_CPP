#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

int optimal(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    int ans = 1;
    for (auto it : s) {
        if (s.find(it-1) == s.end()) {
            int cnt = 1;
            int x = it;
            while (s.find(x+1) != s.end()) {
                x++; cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}
void getter(vector<int>& a, int n) {
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
}
void setter(vector<int>& a, int n) {
    cout<<"Elements: ";
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<"\t";
    } cout<<endl;
}
int main() {
    int n;
    cout<<"Enter size: ";
    cin>>n;
    vector<int> arr(n);

    getter(arr, n);
    cout<<optimal(arr);
    return 0;
}