class Solution {
    int getShortest(unordered_map<int, vector<int>> &paths, int n) {
        queue<pair<int,int>> queue;
        vector<bool> visited(n+1);

        queue.push({0, 0});
        visited[0] = true;

        while (!queue.empty()) {
            auto [node, dist] = queue.front();
            // cout<<node<<" "<<dist<<endl;

            if (node == n) return dist;
            queue.pop();
            
            for (int i:paths[node]) {
                if (!visited[i]) {
                    visited[i] = true;
                    queue.push({i, dist + 1});
                }
            }
        }

        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> paths;
        for (int i=0; i<n-1; i++) {
            paths[i].push_back(i+1);
            // paths[i+1].push_back(i);
        }

        vector<int> shortest;
        for (auto &query : queries) {
            // paths[query[0]].push_back(query[1]);
            // paths[query[1]].push_back(query[0]);
            paths[min(query[0], query[1])].push_back(max(query[0], query[1]));

            shortest.push_back(getShortest(paths, n-1));
        }

        return shortest;
    }
};