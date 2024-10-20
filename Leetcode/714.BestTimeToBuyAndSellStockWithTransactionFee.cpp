class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> next(2), curr(2);

        for (int i=n-1; i>=0; i--) {
            curr[1] = max(next[0] - prices[i], next[1]);
            curr[0] = max(next[1] + prices[i] - fee, next[0]);
            next = curr;
        }

        return curr[1];

        // vector<vector<int>> dp(n+1, vector<int> (2, -1));
        // return helper(prices, n, 0, true, fee, dp);
    }

    int helper(vector<int>& prices, int n, int ind, bool canBuy, int fee, vector<vector<int>> &dp) {
        if (ind >= n) return 0;
        if (dp[ind][canBuy] != -1) return dp[ind][canBuy];

        if (canBuy) {
            int buy = helper(prices, n, ind+1, false, fee, dp) - prices[ind];
            int skip = helper(prices, n, ind+1, true, fee, dp);
            return dp[ind][canBuy] = max(buy, skip);
        } else {
            int sell = helper(prices, n, ind+1, true, fee, dp) + prices[ind] - fee;
            int skip = helper(prices, n, ind+1, false, fee, dp);
            return dp[ind][canBuy] = max(sell, skip);
        }
    }
};