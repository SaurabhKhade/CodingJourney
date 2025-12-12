public class Solution {
    public int MinCostClimbingStairs(int[] cost) {
        var dp = new Dictionary<int, int>();
        return Math.Min(Helper(cost, cost.Length-1, dp), Helper(cost, cost.Length-2, dp));
    }

    int Helper(int[] cost, int index, IDictionary<int, int> dp) {
        if (index < 0) return 0;
        if (dp.ContainsKey(index)) return dp[index];
        return dp[index] = cost[index] + Math.Min(Helper(cost, index-1, dp), Helper(cost, index-2, dp));
    }
}