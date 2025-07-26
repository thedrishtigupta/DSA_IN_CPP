#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,1,1,1,1};
    int n = arr.size();
    int target = 3;
    int ans = 0;
    for (int i = 0; i <= (1<<n)-1; i++) {
        int sum = 0;
        cout<<i<<'\t';
        for (int j = 0; j < n; j++) {
            int b = i & (1<<j);
            cout<<b<<'\t';
            if (b == 0) sum += arr[j];
            else sum -= arr[j];
        }
        cout<<endl<<sum<<endl;
        if (sum == target) ans++;
        cout<<endl;
    }
    cout<<ans;
    return 0;
}