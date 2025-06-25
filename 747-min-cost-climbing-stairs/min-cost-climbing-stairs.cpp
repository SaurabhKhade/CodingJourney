class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> vec(n);
        vec[0] = cost[0], vec[1] = cost[1];

        for (int i=2; i<n; i++) {
            vec[i] = min(vec[i-1], vec[i-2]) + cost[i];
        }

        return min(vec[n-1], vec[n-2]);
    }
};
