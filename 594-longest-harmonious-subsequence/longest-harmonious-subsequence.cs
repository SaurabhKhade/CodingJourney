public class Solution {
    public int FindLHS(int[] nums) {
        Array.Sort(nums);
        int i = 0, j = 0, len = 0;
        while (j < nums.Length) {
            while (nums[j] - nums[i] > 1) {
                i++;
            }

            if (nums[j]-nums[i] == 1) {
                len = Math.Max(len, j-i+1);
            }

            j++;
        }

        return len;
    }
}