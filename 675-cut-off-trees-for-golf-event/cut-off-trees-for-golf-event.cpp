class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<int> heights;
        for (const auto &vec: forest) {
            for (const auto &el: vec) {
                if (el > 1) {
                    heights.emplace_back(el);
                }
            }
        }

        sort(heights.begin(), heights.end());

        int x = 0, y = 0, steps = 0;
        
        for (int i=0; i<heights.size(); i++) {
            auto data = bfs(forest, x, y, heights[i]);

            if (data[0] == -1) return -1;
            steps += data[0];
            x = data[1];
            y = data[2];
            // cout<<x<<" "<<y<<" "<<data[0]<<endl;
        }
        
        return steps;
    }

    array<int, 3> bfs(vector<vector<int>>& forest, int x, int y, int target) {
        // cout<<"call: "<<x<<" "<<y<<" "<<target<<endl;
        queue<array<int, 3>> q;
        
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        q.push({x, y, 0});
        visited[x][y] = true;

        while (!q.empty()) {
            auto &front = q.front();
            x = front[0], y = front[1];
            int steps = front[2];
            q.pop();

            if (forest[x][y] == target) {
                return {steps, x, y};
            }

            if (x>0 && forest[x-1][y] > 0 && !visited[x-1][y]) {
                visited[x-1][y] = true;
                q.push({x-1, y, steps+1});
            }

            if (y>0 && forest[x][y-1] > 0 && !visited[x][y-1]) {
                visited[x][y-1] = true;
                q.push({x, y-1, steps+1});
            }

            if (x < forest.size()-1 && forest[x+1][y] > 0 && !visited[x+1][y]) {
                visited[x+1][y] = true;
                q.push({x+1, y, steps+1});
            }

            if (y < forest[0].size()-1 && forest[x][y+1] > 0 && !visited[x][y+1]) {
                visited[x][y+1] = true;
                q.push({x, y+1, steps+1});
            }
        }
        
        return {-1};
    }
};