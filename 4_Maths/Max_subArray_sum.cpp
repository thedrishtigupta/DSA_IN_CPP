#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int bruteForce(vector<int> a) { // O (n^2)
    int n = a.size();
    int large = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            large = max(large, sum);
        }
    }
    return large;
}

int optimized(vector<int> a) { // O (n)
    int sum = 0;
    int maxSum = INT_MIN;

    for (int i : a) {
        sum += i;
        maxSum = max(maxSum, sum);

        if (sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> a(n);

    cout<<"Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cout<<"Largest sum = "<<optimized(a)<<endl;
    return 0;
}