public class Solution {
    private (int a, int b)[] ops = { (100, 0), (75, 25), (50, 50), (25, 75) };

    double Helper(int a, int b, IDictionary<int, IDictionary<int, double>> dp) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;

        if (dp.ContainsKey(a) && dp[a].ContainsKey(b)) return dp[a][b];

        double probability = 0;

        foreach (var op in ops) {
            probability += Helper(a - op.a, b - op.b, dp) * .25;
        }

        if (!dp.ContainsKey(a)) {
            dp[a] = new Dictionary<int, double>();
        }

        return dp[a][b] = probability;
    }

    public double SoupServings(int n) {
        if (n > 4900) return 1;

        var dict = new Dictionary<int, IDictionary<int, double>>();
        return Helper(n, n, dict);
    }
}