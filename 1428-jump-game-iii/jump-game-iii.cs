public class Solution {
    public bool CanReach(int[] arr, int start) {
        // 0 -> Pending, 1 -> Processing, 2 -> canReach, 3 -> cannotReach
        int[] dp = new int[arr.Length];

        return CanReach(arr, start, dp);
    }

    private bool CanReach(int[] arr, int i, int[] dp) {
        if (arr[i] == 0) return true;
        if (dp[i] == 1) return false;
        if (dp[i] != 0) return dp[i] == 2;

        dp[i] = 1;
        bool canReach = false;
        if (i + arr[i] < arr.Length) {
            canReach |= CanReach(arr, i+arr[i], dp);
        }
        if (i - arr[i] >= 0) {
            canReach |= CanReach(arr, i-arr[i], dp);
        }

        dp[i] = canReach ? 2 : 3;
        // Console.WriteLine($"{i} => {canReach}");
        return canReach;
    }
}