#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<string, int> debt;

void splitWise() {
    multiset<pair<int, string>> m;

    // insert all debts into multiset
    for (auto p : debt) {
        m.insert({p.second, p.first});
    }

    while (!m.empty()) {
        auto start_it = m.begin();
        auto end_it = prev(m.end());

        auto start_pair = *start_it;
        auto end_pair = *end_it;

        m.erase(start_it);
        m.erase(end_it);

        string senderName = start_pair.second;
        int senderAmt = start_pair.first;

        string receiverName = end_pair.second;
        int receiverAmt = end_pair.first;

        int transactionAmt = min(receiverAmt, -senderAmt);

        cout << senderName << " gave " << receiverName << " : " << transactionAmt << endl;

        if (-senderAmt > transactionAmt) {
            m.insert({senderAmt + transactionAmt, senderName});
        }

        if (receiverAmt > transactionAmt) {
            m.insert({receiverAmt - transactionAmt, receiverName});
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string senderName, receiverName;
        int amt;
        cin >> senderName >> receiverName >> amt;

        debt[senderName] -= amt;
        debt[receiverName] += amt;

        if (debt[senderName] == 0) debt.erase(senderName);
        if (debt[receiverName] == 0) debt.erase(receiverName);
    }

    splitWise();
    return 0;
}

/*
Input:
8
A B 300
A D 100
B C 100
B D 200
D C 500
C E 300
E F 100
E G 200
*/
