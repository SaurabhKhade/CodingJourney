public class Solution {
    private (int a, int b)[] ops = { (100, 0), (75, 25), (50, 50), (25, 75) };

    double Helper(int a, int b, double?[,] dp) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;

        if (dp[a,b].HasValue) return dp[a,b].Value;

        double probability = 0;

        foreach (var op in ops) {
            probability += Helper(a - op.a, b - op.b, dp) * .25;
        }

        dp[a,b] = probability;
        return probability;
    }

    public double SoupServings(int n) {
        if (n > 4900) return 1;

        var dp = new double?[n+1, n+1];
        return Helper(n, n, dp);
    }
}