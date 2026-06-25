

/*
Bipartite graph: Divide graph into 2 groups.
- Can colour the whole graph by only 2 colors.
Condition for not bipartite: Odd size cycle
*/


class Solution {
  public:
    bool dfs(int u, int col, unordered_map<int, vector<int>>& adj, vector<int>& color) {
        color[u] = col;
        
        for(auto& v : adj[u]) {
            if (color[v] == color[u]) return false;
            
            if(color[v] == -1) {
                if(!dfs(v, 1-col, adj, color)) return false;
            }
        }
        
        return true;
    }
    bool isBipartite(int n, vector<vector<int>> &edges) {
        // Code here
        vector<int> color(n, -1);
        unordered_map<int, vector<int>> adj;
        
        for(auto& vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if (!dfs(i, 0, adj, color)) return false;
            }
        }
        return true;
    }
};