class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        vector<int> prev(m+1), next(m+1);

        for (int i=0; i<m; i++) {
            prev[i] = 0;
        }

        for (int ind1=1; ind1<=n; ind1++) {
            for (int ind2=1; ind2<=m; ind2++) {
                if (text1[ind1-1] == text2[ind2-1]) {
                    next[ind2] = 1 + prev[ind2-1];
                } else {
                    next[ind2] = max(prev[ind2], next[ind2-1]);
                }
            }
            prev = next;
        }

        return next[m];

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return helper(text1, n-1, text2, m-1, dp);
    }

    // recursive memoization
    int helper(string &text1, int ind1, string &text2, int ind2, vector<vector<int>> &dp) {
        if (ind1 < 0 || ind2 < 0) return 0;
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if (text1[ind1] == text2[ind2]) {
            return dp[ind1][ind2] = 1 + helper(text1, ind1-1, text2, ind2-1, dp);
        }
        return dp[ind1][ind2] = max(helper(text1, ind1-1, text2, ind2, dp), helper(text1, ind1, text2, ind2-1, dp));
    }
};
