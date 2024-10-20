class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for (int i=n-1; i>=0; i--) {
            dp[i][1] = max(dp[i+1][0]-prices[i], dp[i+1][1]);
            dp[i][0] = max(dp[i+2][1]+prices[i], dp[i+1][0]);
        }

        return dp[0][1];

        // memoization
        // vector<vector<int>> dp(n+2, vector<int>(2, 0));
        // return helper(prices, n, 0, true, dp);
    }

    int helper(vector<int>& prices, int n, int ind, bool canBuy, vector<vector<int>> &dp) {
        if (ind >= n) {
            return 0;
        }
        if (dp[ind][canBuy] != -1) return dp[ind][canBuy];
        if (canBuy) {
            int buy = helper(prices, n, ind+1, false, dp) - prices[ind];
            int skip = helper(prices, n, ind+1, true, dp);
            return dp[ind][canBuy] = max(buy, skip);
        } else {
            int sell = helper(prices, n, ind+2, true, dp) + prices[ind];
            int skip = helper(prices, n, ind+1, false, dp);
            return dp[ind][canBuy] = max(sell, skip);
        }
    }
};