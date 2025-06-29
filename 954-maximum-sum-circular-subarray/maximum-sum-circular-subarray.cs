public class Solution {
    public int MaxSubarraySumCircular(int[] nums) {
        int currentMax =0, currentMin =0, globalMax = nums[0], globalMin = nums[0], total = 0;

        foreach (var el in nums) {
            currentMax = Math.Max(currentMax + el, el);
            globalMax = Math.Max(currentMax, globalMax);

            currentMin = Math.Min(currentMin + el, el);
            globalMin = Math.Min(currentMin, globalMin);

            total += el;
        }

        if (total == globalMin) return globalMax;

        return Math.Max(globalMax, total - globalMin);
    }
}