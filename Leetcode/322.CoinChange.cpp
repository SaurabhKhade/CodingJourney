class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, 1e8);

        for (int i=0; i<=amount; i++) {
            if (i%coins[0] == 0) {
                dp[i] = i/coins[0];
            }
        }

        for (int i=1; i<n; i++) {
            for (int j=0; j<=amount; j++) {
                int skip = dp[j];
                int take = (coins[i] <= j) ? dp[j-coins[i]]+1 : 1e8;
                dp[j] = min(skip, take);
            }
        }

        return dp[amount] >= 1e8 ? -1 : dp[amount];
    }
};
