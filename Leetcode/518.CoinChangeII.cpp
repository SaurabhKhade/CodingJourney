class Solution {
    const int LIMIT = INT_MAX;
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        long take, skip;
        vector<int> dp(amount+1);

        for (int i=0; i <= amount; i++) {
            dp[i] = i%coins[0] == 0;
        }

        for (int i=1; i<n; i++) {
            for (int j=0; j<=amount; j++) {
                skip = dp[j];
                take = (coins[i] <= j) ? dp[j-coins[i]] : 0;
                dp[j] = (skip + take)%LIMIT;
            }
        }
        return dp[amount];
    }
};