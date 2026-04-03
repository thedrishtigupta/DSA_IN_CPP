
#include <iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr, int s, int m, int e) {
    int i = s, j = m+1;

    vector<int> temp;

    int count = 0;

    while(i <= m && j <= e) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else {
            count += (m-i+1);
            temp.push_back(arr[j++]);
        }
    }

    while (i <= m) temp.push_back(arr[i++]);
    while (j <= e) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) arr[k+s] = temp[k];

    return count;
}

int mergeSort(vector<int>& arr, int s, int e) {
    if (s >= e) return 0;

    int m = s + ((e-s)/2);
    int left = mergeSort(arr, s, m);
    int right = mergeSort(arr, m+1, e);

    int curr = merge(arr, s, m, e);

    return curr + left + right;
}

int countInversions(vector<int>& arr) {
    int s = 0, e = arr.size()-1;

    return mergeSort(arr, s, e);
}

int main() {
    int n; cin>>n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin>>arr[i];

    cout<<countInversions(arr)<<endl;
    return 0;
}