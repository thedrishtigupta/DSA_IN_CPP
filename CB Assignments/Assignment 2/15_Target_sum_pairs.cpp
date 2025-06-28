#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

void optimal(int arr[], int n, int target) {
    unordered_map<int, int> m;
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        int first = arr[i];
        int second = target - first;

        if (m.find(second) != m.end()) {
            int a = min(first, second);
            int b = max(first, second);
            ans.emplace_back(a, b);
        }
        m[first] = i;
    }
    sort(ans.begin(), ans.end());
    for (auto p : ans) {
        cout << p.first << " and " << p.second << endl;
    }

}

void targetSum(int arr[], int n, int target) {
    vector<pair<int, int>> ans;

    int i = 0, j = n - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum > target) {
            j--;
        } else if (sum < target) {
            i++;
        } else {
            ans.push_back({arr[i], arr[j]});
            i++;
            j--;
        }
    }

    sort(ans.begin(), ans.end());

    for (auto p : ans) {
        cout << p.first << " and " << p.second << endl;
    }
}

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 1000) return 0;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    sort(arr, arr + n);
    optimal(arr, n, target);

    delete[] arr;

    return 0;
}
