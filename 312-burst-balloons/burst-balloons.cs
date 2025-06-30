public class Solution {
    public int MaxCoins(int[] nums) {
        int n = nums.Length;
        var list = new List<int>(nums);
        list.Insert(0, 1);
        list.Add(1);
        var dp = new int[n+1, n+1];
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                dp[i,j] = -1;
            }
        }

        return Helper(list, 1, n, dp);
    }

    int Helper(List<int> nums, int low, int high, int[,] dp) {
        if (low > high) return 0;
        if (dp[low,high] != -1) return dp[low,high];

        int max = 0;
        for (int i=low; i<=high; i++) {
            var value = nums[low-1] * nums[i] * nums[high+1] + Helper(nums, low, i-1, dp) + Helper(nums, i+1, high, dp);
            max = Math.Max(max, value);
        }

        return dp[low,high] = max;
    }
}