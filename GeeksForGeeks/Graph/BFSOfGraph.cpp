class Solution {
  public:
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool> visited(n);
        vector<int> bfs;
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            bfs.push_back(front);
            
            for (int node:adj[front]) {
                if (!visited[node]) {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
        
        return bfs;
    }
};