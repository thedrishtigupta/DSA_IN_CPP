

class Solution {
  public:
    void dfs(int u, int par, unordered_map<int, vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        
        for(auto& v : adj[u]) {
            if (v == par) continue;
            if(!visited[v]) dfs(v, u, adj, visited, st);
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        
        for(auto& vec : edges) {
            adj[vec[0]].push_back(vec[1]);
        }
        
        vector<bool> visited(V, false);
        vector<int> result;
        stack<int>st;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) dfs(i, -1, adj, visited, st);
        }
        
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};