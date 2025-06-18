public class Solution {
    public int[][] DivideArray(int[] nums, int k) {
        Array.Sort(nums);
        int[][] result = new int[nums.Count()/3][];
        int i = 0;
        for (int j=0; j<nums.Count(); j+=3) {
            if (nums[j]+k < nums[j+2]) {
                return new int[0][];
            } else {
                result[i] = new int[3];
                result[i][0] = nums[j];
                result[i][1] = nums[j+1];
                result[i][2] = nums[j+2];
                i++;
            }
        }

        return result;
    }
}