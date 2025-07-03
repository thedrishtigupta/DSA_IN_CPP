#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> optimal(int a[], int b[], int n, int m) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            } i++;
        } else {
            if (ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            } j++;
        }
    }

    while (i < n) {
        if (ans.empty() || ans.back() != a[i]) {
            ans.push_back(a[i]);
        } i++;
    }

    while (j < m) {
        if (ans.empty() || ans.back() != b[j]) {
            ans.push_back(b[j]);
        } j++;
    }
    return ans;
}

void print(vector<int> a) {
    for (int val : a) {
        cout << val << "\t";
    }
    cout << endl;
}
int main() {
    int n, m;
    cin >> n >> m;

    int* a = new int[n];
    int* b = new int[m];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    print(optimal(a, b, n ,m));


    delete[] a;
    delete[] b;
    return 0;
}
