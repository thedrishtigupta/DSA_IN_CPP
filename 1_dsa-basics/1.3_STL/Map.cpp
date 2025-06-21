#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    
    // creation
    unordered_map <string, int> m;

    // initialization 1
    m["my"] = 1;

    // 2
    pair<string, int> pair1 = make_pair("name", 2);
    m.insert(pair1);
    // 3
    pair<string, int> pair2("drishti", 3);
    m.insert(pair2);

    // search

    cout<<m["my"]<<endl;
    cout<<m.at("drishti")<<endl;

    cout<<m["unknown"]<<endl;
    cout<<m.at("unknown")<<endl;


    // size
    cout<<m.size()<<endl;

    // to check if present
    cout<<m.count("bro")<<endl;
    cout<<m.count("name")<<endl;

    // erase/ delete
    m.erase("name");
    cout<<m.size()<<endl;

    //traveserse/ printing

    for (auto i : m) {
        cout<< i.first << " "<<i.second <<endl;
    }

    // using iterators
    unordered_map <string, int> :: iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}