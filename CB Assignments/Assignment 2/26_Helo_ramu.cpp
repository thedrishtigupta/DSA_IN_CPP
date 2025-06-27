#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
	if ( T < 1 || T > 1000) return 0;

    while (T--) {
        int c[4];
        for (int i = 0; i <4; i++) {
            cin>>c[i];
			if (c[i] < 1 || c[i] > 1000) return 0;
        }

        int n;
        cin>> n;
		if ( n < 1 || n > 1000) return 0;

        int m;
        cin>>m;
		if ( m < 1 || m > 1000) return 0;

        int* rick = new int[n];
        int* cab = new int[m];

        for (int i = 0; i < n; i++) {
            cin>>rick[i];
			if (rick[i] < 0 || rick[i] > 1000) return 0;
        }

        for (int i = 0; i < m; i++) {
            cin>>cab[i];
			if (cab[i] < 0 || cab[i] > 1000) return 0;
        }

        int minR = 0, minC = 0;

        for (int i = 0; i < n; i++) {
            minR += min(rick[i]*c[0], c[1]);
        }
        int totalR = min(minR, c[2]);

        for (int i = 0; i < m; i++) {
            minC += min(cab[i]*c[0], c[1]);
        }
        int totalC = min(minC, c[2]);

        int TotalCost = min(totalC+ totalR, c[3]);

        cout<<TotalCost<<endl;


        delete[] rick;
        delete[] cab;
    }
    return 0;
}