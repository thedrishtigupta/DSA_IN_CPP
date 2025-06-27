#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int T;
    cin>>T;
	if (T < 1 || T > 100) return 0;

    while (T--) {
        int n;
        cin>>n;
		if (n < 2 || n > 10000) return 0;

        int* arr = new int[n];
        for (int i = 0; i <n; i++) {
            cin>>arr[i];
			if (arr[i] > 1000001) return 0;
        }

        int tar;
        cin>>tar;

        sort(arr, arr+n);

        int i = 0, j = n-1;
        int minDiff = INT_MAX;
        int ans1 = 0, ans2 = 0;

        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == tar) {
                int diff = arr[j] - arr[i];
                if (diff < minDiff) {
                    ans1 = arr[i];
                    ans2 = arr[j];
                }
                i++; j--;
            } else if (sum > tar) j--;
            else i++;
        }

        cout<<"Deepak should buy roses whose prices are "<<ans1<<" and "<<ans2<<"."<<endl;

        delete[] arr;
    }
    
    return 0;
}