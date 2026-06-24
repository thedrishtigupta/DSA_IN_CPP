
/*
We dont use visited array here, because we only push into queue when inDegree becomes 0!
So there's no chance of pushing node into queue multiple times.

Kahn's algo : Used for Topological sort using BFS.
1. Compute inDegree of every node.
2. Push all nodes with inDegree 0 into the queue.
3. Repeatedly:
    a. Pop a node.
    b. For each outgoing edge u → v:
    c. Decrement inDegree[v].
4. If inDegree[v] == 0, push v into the queue.
*/

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(V, 0);
        
        for(auto& vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            inDegree[vec[1]]++;
        }
        
        vector<int> result;
        queue<int> q;
        
        for(int i = 0; i < V; i++) if(!inDegree[i]) q.push(i);
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            result.push_back(u);
            
            for(int v : adj[u]) {
                inDegree[v]--;
                
                if(!inDegree[v]) q.push(v);
            }
        }
        
        
        return result;
    }
};