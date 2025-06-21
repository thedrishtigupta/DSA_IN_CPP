#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector <int> vec = {1,2,3,4,5};

    cout<<"Size= " <<vec.size()<<endl;
    cout<<"Capacity= "<<vec.capacity()<<endl;

    vec.insert(vec.begin()+2, 100);

    cout<<"Size= " <<vec.size()<<endl;
    cout<<"Capacity= "<<vec.capacity()<<endl;

    vec.insert(vec.begin()+2, 100);

    cout<<"Size= " <<vec.size()<<endl;
    cout<<"Capacity= "<<vec.capacity()<<endl;
    vec.clear();
    cout<<"Size= " <<vec.size()<<endl;
    cout<<"Capacity= "<<vec.capacity()<<endl;
    return 0;
}