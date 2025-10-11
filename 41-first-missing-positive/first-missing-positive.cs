public class Solution {
    public int FirstMissingPositive(int[] nums) {
        for (int i=0; i<nums.Length; i++) {
            if (nums[i] <= 0) {
                nums[i] = 10000000;
            }
        }

        for (int i=0; i<nums.Length; i++) {
            var abs = Math.Abs(nums[i]);
            if (abs <= nums.Length && abs > 0) {
                nums[abs-1] = -1 * Math.Abs(nums[abs-1]);
            }
        }

        for (int i=0; i<nums.Length; i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }

        return nums.Length + 1;
    }
}