public class Solution {
    public int RemoveDuplicates(int[] nums) {
        if (nums.Length < 2) return nums.Length;

        int i = 2, j = 2;
        while (j < nums.Length) {
            if (nums[j] == nums[i-1] && nums[j] == nums[i-2]) {
                j++;
            }
            else {
                nums[i] = nums[j];
                i++; j++;
            }
        }

        return i;
    }
}

// 0 0 1 1 2 3 3 3 3
//               i
//                   j