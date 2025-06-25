const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

// #define LC_HACK
// #ifdef LC_HACK
// const auto __ = []() {
//     struct ___ {
//         static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
//     };
//     std::atexit(&___::_);
//     return 0;
// }();
// #endif

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<vector<int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    visited[i][j] = true;
                    q.push({i, j, 0});
                }
                grid[i][j] = 0;
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front[0], y= front[1], height = front[2];
            grid[x][y] = height;

            if (x > 0 && !visited[x-1][y]) {
                q.push({x - 1, y, height+1});
                visited[x - 1][y] = true;
            }

            if (x < m - 1 && !visited[x + 1][y]) {
                q.push({x + 1, y, height+1});
                visited[x + 1][y] = true;
            }

            if (y > 0 && !visited[x][y - 1]) {
                q.push({x, y - 1, height+1});
                visited[x][y - 1] = true;
            }

            if (y < n - 1 && !visited[x][y + 1]) {
                q.push({x, y + 1, height+1});
                visited[x][y + 1] = true;
            }
        }

        return grid;
    }
};
