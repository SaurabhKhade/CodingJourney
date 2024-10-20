class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> q;
        int m = grid.size(), n = grid[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }

        int maxTime = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            maxTime = max(maxTime, front.second);

            if (front.first.first > 0 && grid[front.first.first-1][front.first.second] == 1) {
                grid[front.first.first-1][front.first.second] = 0;
                q.push({{front.first.first-1, front.first.second}, front.second+1});
            }
            if (front.first.second > 0 && grid[front.first.first][front.first.second-1] == 1) {
                grid[front.first.first][front.first.second-1] = 0;
                q.push({{front.first.first, front.first.second-1}, front.second+1});
            }
            if (front.first.first < m-1 && grid[front.first.first+1][front.first.second] == 1) {
                grid[front.first.first+1][front.first.second] = 0;
                q.push({{front.first.first+1, front.first.second}, front.second+1});
            }
            if (front.first.second < n-1 && grid[front.first.first][front.first.second+1] == 1) {
                grid[front.first.first][front.first.second+1] = 0;
                q.push({{front.first.first, front.first.second+1}, front.second+1});
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return maxTime;
    }
};