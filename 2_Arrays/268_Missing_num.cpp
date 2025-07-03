#include <iostream>
#include <vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expSum = n*(n+1)/2;
    int sum = 0;

    for (int val : nums) sum += val;
    
    return expSum - sum;
}
int main() {
    int n;
    cin>>n;

    vector<int> num(n);
    return 0;
}