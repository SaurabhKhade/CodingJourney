class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(V,vector<int>());
        
        for (const auto &pair: edges) {
            graph[pair.first].push_back(pair.second);
            graph[pair.second].push_back(pair.first);
        }
        
        return graph;
    }
};