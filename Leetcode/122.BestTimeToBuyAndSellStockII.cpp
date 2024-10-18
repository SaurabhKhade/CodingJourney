class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        pair<int, int> nextDay, currentDay;

        nextDay.first = prices[n-1];
        nextDay.second = 0;

        for (int i=n-2; i>=0; i--) {
            // can buy
            currentDay.second = max(nextDay.first - prices[i], nextDay.second);
            // cannot buy (can sell)
            currentDay.first = max(nextDay.second + prices[i], nextDay.first);
            nextDay = currentDay;
        }

        return currentDay.second;

        // recursive memoization
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return helper(prices, n-1, 0, true, dp);
    }

    int helper(vector<int>& prices, int n, int ind, bool canBuy, vector<vector<int>> &dp) {
        if (n==ind) {
            if (canBuy) return 0;
            else return prices[ind];
        }
        if (dp[ind][canBuy] != -1) return dp[ind][canBuy];
        
        if (canBuy) {
            int buy = helper(prices, n, ind+1, false, dp) - prices[ind];
            int skip = helper(prices, n, ind+1, true, dp);
            return dp[ind][canBuy] = max(buy, skip);
        } else {
            int sell = helper(prices, n, ind+1, true, dp) + prices[ind];
            int skip = helper(prices, n, ind+1, false, dp);
            return dp[ind][canBuy] = max(sell, skip);
        }
    }
};