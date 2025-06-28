#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
    targetSum(arr, n, target);

    delete[] arr;

    return 0;
}
