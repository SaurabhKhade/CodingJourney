class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mx = INT_MIN, sum = 0;
        unordered_map<int, bool> visited;

        for(auto i: nums) {
            if (!visited[i]) {
                visited[i] = true;
                mx = max(mx, i);
                sum = max(sum, sum + i);
            }
        }

        if (mx < 0) return mx;
        return sum;
    }
};