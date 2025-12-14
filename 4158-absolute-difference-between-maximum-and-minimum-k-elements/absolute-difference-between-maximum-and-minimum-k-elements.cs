public class Solution {
    public int AbsDifference(int[] nums, int k) {
        nums = nums.Order().ToArray();

        int minSum = 0, maxSum = 0;

        for (int i=0; i<k; i++) {
            minSum += nums[i];
            maxSum += nums[nums.Length - i - 1];
        }

        return maxSum - minSum;
    }
}