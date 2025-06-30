public class Solution {
    public int LongestCommonSubsequence(string text1, string text2) {
        var dp = new int[text1.Length, text2.Length];

        for (int i=0; i<text1.Length; i++) {
            for (int j=0; j<text2.Length; j++) {
                dp[i,j] = -1;
            }
        }

        return Helper(text1, text2, 0, 0, dp);
    }

    int Helper(string text1, string text2, int i, int j, int[,] dp) {
        if (i == text1.Length || j == text2.Length) {
            return 0;
        }
        if (dp[i,j] != -1) return dp[i,j];

        int max = 0;

        if (text1[i] == text2[j]) {
            max = Helper(text1, text2, i+1, j+1, dp) + 1;
        } else {
            max = Helper(text1, text2, i+1, j, dp);
            max = Math.Max(max, Helper(text1, text2, i, j+1, dp));
        }

        return dp[i,j] = max;
    }
}