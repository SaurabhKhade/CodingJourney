class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int cnt = n;

        for (int i=0; i<n; i++) {
            dp[i][i] = true;
        }

        for (int i=1; i<n; i++) {
            for (int j=0; j+i<n; j++) {
                if (s[j] == s[j+i] && (i == 1 || dp[j+1][j+i-1])) {
                    dp[j][j+i] = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }
};