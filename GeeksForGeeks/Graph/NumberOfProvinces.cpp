class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V);

        int provinces = 0;

        for (int i=0; i<V; i++) {
            if (visited[i]) continue;
            provinces++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty()) {
                int front = q.front();
                q.pop();
                for (int j=0; j<V; j++) {
                    if (adj[front][j] && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }

        return provinces;
    }
};