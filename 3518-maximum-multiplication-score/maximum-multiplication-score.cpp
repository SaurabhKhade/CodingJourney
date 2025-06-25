class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> dp(4, vector<long long>(b.size(), -1));
        return helper(a, b, 0, 0, dp);
    }

    long long helper(vector<int> &a, vector<int> &b, int i, int j, vector<vector<long long>> &dp) {
        if (i == 4) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        long long prod = helper(a, b, i+1, j+1, dp) + (long long)a[i]*b[j];

        if ((b.size()-j) > (4-i)) {
            prod = max(prod, helper(a, b, i, j+1, dp));
        }

        return dp[i][j] = prod;
    }
};