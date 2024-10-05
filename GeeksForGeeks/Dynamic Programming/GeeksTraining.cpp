class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(3, vector<int>(n));
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[0][1];
        dp[2][0] = arr[0][2];
        
        for (int i=1; i<n; i++) {
            dp[0][i] = arr[i][0] + max(dp[1][i-1], dp[2][i-1]);
            dp[1][i] = arr[i][1] + max(dp[0][i-1], dp[2][i-1]);
            dp[2][i] = arr[i][2] + max(dp[0][i-1], dp[1][i-1]);
        }
        
        return max(dp[0][n-1], max(dp[1][n-1], dp[2][n-1]));
    }
};