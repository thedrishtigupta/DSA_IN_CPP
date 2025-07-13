#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> optimal(vector<int>& arr) {
    int n = arr.size();

    vector<int> ans;
    ans.push_back(arr[n-1]);
    int max = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > max) {
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void getter(vector<int>& a, int n) {
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
}
void setter(vector<int>& a) {
    int n = a.size();
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
    
    vector<int> ans = optimal(arr);
    for (int x : ans) {
        cout << x << "\t";
    }
    cout<<endl;
    return 0;
}