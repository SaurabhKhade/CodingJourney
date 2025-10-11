public class Solution {
    public int FirstMissingPositive(int[] nums) {

        // Eliminate the negative numbers and zeroes, as they aren't useful for us
        for (int i=0; i<nums.Length; i++) {
            if (nums[i] <= 0) {
                nums[i] = 10000000;
            }
        }

        // if the value of current element lies within array range, change the element at that position to negative, to mark it as visited
        for (int i=0; i<nums.Length; i++) {
            var abs = Math.Abs(nums[i]);
            if (abs <= nums.Length && abs > 0) {
                nums[abs-1] = -1 * Math.Abs(nums[abs-1]);
            }
        }

        // check the first non negative number
        // it means that element with that position value is absent
        for (int i=0; i<nums.Length; i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }

        // if nothing found, it means array contains numbers from 1 to n
        return nums.Length + 1;
    }
}