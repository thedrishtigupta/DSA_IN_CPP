#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    int* parent;
    int* rank;
    int n;

    DSU(int N) {
        n = N + 1;
        parent = new int[n];
        rank = new int[n];

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int get_leader(int u) {
        if (u == parent[u]) return u;
        return parent[u] = get_leader(parent[u]); // path compression
    }

    void union_leader(int u, int v) {
        int leader_u = get_leader(u);
        int leader_v = get_leader(v);

        if (leader_u != leader_v) {
            if (rank[leader_u] < rank[leader_v])
                swap(leader_u, leader_v);

            parent[leader_v] = leader_u;
            if (rank[leader_u] == rank[leader_v])
                rank[leader_u]++;
        }
    }
};

class Tuple {
public:
    int u, v, dist;
    Tuple(int u, int v, int dist) : u(u), v(v), dist(dist) {}
};

bool comp(Tuple &a, Tuple &b) {
    return a.dist < b.dist;
}

int main() {
    vector<Tuple> edges;
    edges.push_back({1, 2, 1});
    edges.push_back({1, 3, 2});
    edges.push_back({4, 2, 8});
    edges.push_back({3, 4, 3});
    edges.push_back({4, 5, 4});
    edges.push_back({3, 5, 5});

    sort(edges.begin(), edges.end(), comp);

    DSU d(5);
    int minWeight = 0;

    for (auto t : edges) {
        int u = t.u;
        int v = t.v;
        int dist = t.dist;

        if (d.get_leader(u) != d.get_leader(v)) {
            d.union_leader(u, v);
            minWeight += dist;
        }
    }

    cout << "Minimum Spanning Tree Weight = " << minWeight << endl;

    return 0;
}
