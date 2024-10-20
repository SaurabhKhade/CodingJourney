class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, n-1, 0, true, 0, dp);
    }

    int helper(vector<int>& prices, int n, int ind, bool canBuy, int buys, vector<vector<vector<int>>> &dp) {
        if (n==ind) {
            return canBuy ? 0 : prices[n];
        }
        if (canBuy && buys == 2) {
            return 0;
        }
        if (dp[ind][canBuy][buys] != -1) return dp[ind][canBuy][buys];

        if (canBuy) {
            int buy = helper(prices, n, ind+1, false, buys+1, dp) - prices[ind];
            int skip = helper(prices, n, ind+1, true, buys, dp);
            return dp[ind][canBuy][buys] = max(buy, skip);
        } else {
            int sell = helper(prices, n, ind+1, true, buys, dp) + prices[ind];
            int skip = helper(prices, n, ind+1, false, buys, dp);
            return dp[ind][canBuy][buys] = max(sell, skip);
        }
    }
};