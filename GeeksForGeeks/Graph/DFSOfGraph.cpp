class Solution {
  public:
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n);
        vector<int> dfsList;
        dfs(adj, 0, visited, dfsList);
        return dfsList;
    }
    
    void dfs(vector<vector<int>>& adj, int node, vector<bool> &visited, vector<int> &dfsList) {
        if (visited[node]) return;
        visited[node] = true;
        dfsList.push_back(node);
        
        for (const int &i:adj[node]) {
            dfs(adj, i, visited, dfsList);
        }
    }
};