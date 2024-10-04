class Solution {
  unordered_map<int, int> map;
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int dp[n+1];
        dp[1] = 0;
        dp[2] = abs(height[1] - height[0]);
        
        for (int i=3; i<=n; i++) {
            int a = dp[i-1] + abs(height[i-1] - height[i-2]);
            int b = dp[i-2] + abs(height[i-1] - height[i-3]);
            dp[i] = min(a,b);
        }
        
        return dp[n];
    }
};