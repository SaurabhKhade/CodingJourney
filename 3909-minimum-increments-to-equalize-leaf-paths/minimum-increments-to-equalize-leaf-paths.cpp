class Solution {
    int nodes = 0;
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> tree(n);
        for (auto edge: edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n);

        traverse(0, tree, cost, visited);

        return nodes;
    }

    long long traverse(int node, vector<vector<int>> &tree, vector<int>& cost, vector<bool>& visited) {
        vector<long long> childCosts;
        long long mx = 0;
        visited[node] = true;

        for (auto child: tree[node]) {
            if (visited[child]) continue;
            long long pathCost = traverse(child, tree, cost, visited);
            mx = max(mx, pathCost);
            childCosts.push_back(pathCost);
        }

        int updates = 0;
        for (int i=0; i<childCosts.size(); i++) {
            if (childCosts[i] < mx) {
                updates++;
            }
        }

        nodes += updates;

        return mx + cost[node];
    }
};