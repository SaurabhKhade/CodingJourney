public class Solution {
    public int NumTrees(int n) {
        var dp = new int[n+1];
        return Helper(n, dp);
    }

    public int Helper(int n, int[] dp) {
        // Console.WriteLine(n);
        if (n == 0) return 1;
        if (dp[n] != 0) return dp[n];

        int count = 0;

        for (int i=1; i<=n; i++) {
            count += Helper(i-1, dp) * Helper(n-i, dp);
        }

        return dp[n] = count;        
    }
}