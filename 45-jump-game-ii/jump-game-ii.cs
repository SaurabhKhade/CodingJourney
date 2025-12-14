public class Solution {
    public int Jump(int[] nums) {
        var res = new int[nums.Length];
        Array.Fill(res, int.MaxValue);
        res[0] = 0;

        for (int i=0; i<nums.Length; i++) {
            for (int j = Math.Min(res.Length-1, i + nums[i]); j > i && res[i] + i < res[j]; j--){
                res[j] = res[i]+1;
            }
        }

        return res.Last();
    }
}