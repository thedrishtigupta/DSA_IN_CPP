#include <iostream>
#include <set>
using namespace std;

int main() {

    set <int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);

    for (auto i : s) {
        cout<<i<<"\t";
    }
    cout<<endl;

    s.insert(5);
    s.insert(4);
    s.insert(2);
    s.insert(1);

    for (auto i : s) {
        cout<<i<<"\t";
    }
    cout<<endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    for (auto i : s) {
        cout<<i<<"\t";
    }
    cout<<endl;

    cout<<"is 5 present or not? = "<<s.count(5)<<endl;

    set<int>::iterator itr = s.find(4);

    for (auto it = itr; it != s.end(); it++) {
        cout<< *it<<"\t";
    }
    cout<<endl;


    return 0;
}