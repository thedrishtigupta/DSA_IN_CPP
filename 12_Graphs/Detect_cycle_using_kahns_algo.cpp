


class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        
        vector<int>inDegree(V);
        
        for(auto& vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            inDegree[vec[1]]++;
        }
        
        queue<int> q;
        int cnt = 0;
        
        for(int i = 0; i < V; i++) if(!inDegree[i]) {
            q.push(i); cnt++;
        }
        
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            
            for(int v : adj[u]) {
                inDegree[v]--;
                if (!inDegree[v]) {q.push(v); cnt++;}
            }
        }
        
        return cnt != V;
    }
};