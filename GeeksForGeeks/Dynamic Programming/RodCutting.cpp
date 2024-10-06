class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n+1, 0);
        
        dp[0] = 0;
        
        for (int i=1; i<=n; i++) {
            int mx = 0;
            for (int j=1; j<=i; j++) {
                mx = max(mx, dp[i-j] + price[j-1]);
            }
            
            dp[i] = mx;
        }
        
        return dp[n];
    }
};