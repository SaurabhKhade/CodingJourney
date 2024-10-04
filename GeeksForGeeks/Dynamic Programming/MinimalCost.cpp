class Solution {
    unordered_map<int, int> map;
  public:
    int minimizeCost(int k, vector<int>& arr) {
        map.clear();
        return helper(k, arr, arr.size()-1);
    }
    
    int helper(int k, vector<int>& arr, int n) {
        if (n <= 0) return 0;
        if (map.find(n) != map.end()) return map[n];
        int cost = INT_MAX;
        
        for (int i=1; n-i>=0 && i<=k; i++) {
            cost = min(cost, helper(k, arr, n-i) + abs(arr[n] - arr[n-i]));
        }
        return map[n] = cost;
    }
};