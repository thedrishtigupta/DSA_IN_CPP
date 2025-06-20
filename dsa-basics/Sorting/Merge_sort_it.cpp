#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> A = {2,8,15,18};
    vector<int> B = {5, 9, 12, 17};
    vector<int> C;

    int m = A.size(), n = B.size();

    int i = 0, j = 0;
    while (i < m && j < n) {
        if (A[i] < B[j]) {
            C.push_back(A[i++]);
        } else {
            C.push_back(B[j++]);
        }
    }

    while (i < m) C.push_back(A[i++]);
    while (j < n) C.push_back(B[j++]);

    int p = C.size();
    for (int t = 0; t < p; t++) {
        cout<<C[t] <<"\t";
    }
    cout <<endl;
    return 0;
}