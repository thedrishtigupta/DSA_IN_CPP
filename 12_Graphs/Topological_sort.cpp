#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>
using namespace std;

template<typename T>
class Graph {
public:
	unordered_map<T, list<T>> adj;

	void addEdge(T u, T v, bool bidir = false) {
		adj[u].push_back(v);
		if (bidir) {
			adj[v].push_back(u);
		}
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << " : ";
			for (auto child_pair : p.second) {
				cout << "( " << child_pair.first << ", " << child_pair.second << " ) ";
			}
			cout << endl;
		}
	}

    void topologicalSort() {
        unordered_map<T, int> inDegree;

        for(auto p: adj) {
            for(auto ch: p.second) {
                if(!inDegree[ch]) inDegree[ch] = 0;
                inDegree[ch]++;
            }
        }

        queue<T> q;
        for(auto p: adj) {
            if(!inDegree.count(p.first)) { // 0 inDegree hai
                q.push(p.first);
            }
        }

        while(!q.empty()) {
            T d = q.front();
            q.pop();
            cout<<d<<" ";

            for(auto ch : adj[d]) {
                if(--inDegree[ch] == 0) q.push(ch);
            }
        }

    }

    void topologicalSortHelper(T src, deque<T> &q, unordered_map<T, bool>& visited) {
        for(auto ch : adj[src]) {
            if(!visited[ch]) topologicalSortHelper(ch, q, visited);
        }
        visited[src] = true;
        q.push_front(src);
    }

    void topologicalDFS() {
        deque<T> q;
        unordered_map<T, bool> visited;

        for(auto p : adj) {
            if(!visited[p.first]) topologicalSortHelper(p.first, q, visited);
        }
        for(auto d : q) cout<<d<<" ";
    }
};


int main() {
	Graph <string> g;

	g.addEdge("C++", "WebDev");
	g.addEdge("C++", "Android");
    g.addEdge("Java", "Android");
    g.addEdge("WebDev", "CP");
    g.addEdge("WebDev", "DS");
    g.addEdge("CP", "Web3");
    g.addEdge("DS", "Web3");
    g.addEdge("Android", "CS");

	g.topologicalDFS();

	return 0;
}