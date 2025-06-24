#include <iostream>
using namespace std;

void printCelsius(int start, int end, int step) {

    for (int i = start; i <= end; i+=step) {
        cout<<i<<"\t"<<(int)((5/9.0)*(i-32))<<endl;
    }
}
int main() {
    
    int start, end, step;
    cin>>start>>end>>step;

	if (start < 0 || start > 100 || end < start || end > 500 || 
	    step < 0 || step > 150) return 0;

    printCelsius(start, end, step);
    
    return 0;
}