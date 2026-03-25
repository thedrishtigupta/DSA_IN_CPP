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
        cout<<"BFS: ";
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
        cout<<endl;
    }

    void dfsHelper(T u, unordered_map<T, bool>& visited) {
        cout<<u<<" ";
        visited[u] = true;

        for(auto& v : adj[u]){
            if (!visited[v]) dfsHelper(v, visited);
        }
    }

    void dfs(T src) {
        unordered_map<T, bool> visited;
        cout<<"DFS: ";
        dfsHelper(src, visited);
        cout<<endl;
    }
    bool isCyclicHelper(T src, unordered_map<T, bool>& visited, T parent) {

        visited[src] = true;

        for(auto& v : adj[src]) {
            if (!visited[v]) return isCyclicHelper(v, visited, src);
            else if (v != parent) return true;
        }
        return false;
    }
    void isCyclic(T src) {
        unordered_map<T, bool> visited;
        cout<<"Is Cyclic: ";
        bool ans = isCyclicHelper(src, visited, -1);
        if (ans) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }

    bool isCyclicBFS(T src) {
        queue<pair<T, T>> q;
        unordered_map<T, bool> visited;

        visited[src] = true;
        q.push({src, -1});
        cout<<"Is Cyclic (BFS): ";
        while(!q.empty()) {
            T u = q.front().first;
            T parentU = q.front().second;
            q.pop();

            for(auto& v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, u});
                } else if (v != parentU) return true;
            }
        }
        return false;
    }
};

int main() {
    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3, 5);

    g.print();

    g.bfs(0);
    g.dfs(0);
    g.isCyclic(0);

    bool ans = g.isCyclicBFS(0);
    if (ans) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}