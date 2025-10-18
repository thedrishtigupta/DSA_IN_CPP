#include <iostream>
#include <unordered_map>
#include<string>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph {
public:
	unordered_map<string, list<pair<string, int>> adj;

	void addEdge(string u, string v, int dist, bool bidir = true) {
		adj[u].emplace_back(v, dist);
		if (bidir) {
			adj[v].emplace_back(u, dist);
		}
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << " : ";
			for (auto childPair : p.second) {
				cout << "( " << childPair.first<< ", "<< childPair.second <<" )";
			}
			cout << endl;
		}
	}

	void bfs(T src) {
		queue<T> q;
		unordered_map<T, bool> visited;
		visited[src] = true;
		q.push(src);

		while (!q.empty()) {
			int node = q.front();
			cout << node << " ";
			q.pop();

			for (auto ch : adj[node]) {
				if (!visited[ch]) {
					q.push(ch);
					visited[ch] = true;
				}
			}
		}
		cout << endl;
	}


	int SSSP(T src, T des) {
		queue<T> q;
		unordered_map<T, bool> visited;
		unordered_map<T, T> parent;
		unordered_map<T, int> dist;

		visited[src] = true;
		q.push(src);
		parent[src] = src;
		dist[src] = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto ch : adj[node]) {
				if (!visited[ch]) {
					parent[ch] = node;
					dist[ch] = dist[node] + 1;
					q.push(ch);
					visited[ch] = true;
				}
			}
		}

		T des_copy = des;
		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;

		des = des_copy;
		return dist[des];
	}
};


int main() {

	Graph<int> g;
	g.addEdge("Amritsar", "Jaipur", 4);
    g.addEdge("Mumbai", "Jaipur", 8);
    g.addEdge("Delhi", "Jaipur", 2);
    g.addEdge("Amritsar", "Agra", 1);
    g.addEdge("Delhi", "Agra", 1);
    g.addEdge("Agra", "Bhopal", 2);
    g.addEdge("Mumbai", "Bhopal", 3);

	
	return 0;
}