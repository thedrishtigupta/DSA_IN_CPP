#include <iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

template<typename T>

class Graph {
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool biDir = true) {
        adj[u].push_back(v);
        if (biDir) adj[v].push_back(u);
    }

    void print() {
        for (auto &v : adj) {
            cout<<v.first<<" : ";
            for(auto &e : v.second) {
                cout<<e<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(T src) {
        queue<T> q;
        unordered_map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            T u = q.front(); q.pop();
            cout<<u<<" ";

            for(auto &v : adj[u]){
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main() {
    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1,3);
    g.addEdge(2,3);

    g.print();

    g.bfs(0);
    return 0;
}