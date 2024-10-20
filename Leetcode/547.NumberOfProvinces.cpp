class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n);

        int provinces = 0;

        for (int i=0; i<n; i++) {
            if (visited[i]) continue;
            provinces++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty()) {
                int front = q.front();
                q.pop();
                for (int j=0; j<n; j++) {
                    if (isConnected[front][j] && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }

        return provinces;
    }
};