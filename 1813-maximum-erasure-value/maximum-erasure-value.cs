public class Solution {
    public int MaximumUniqueSubarray(int[] nums) {
        var dict = new Dictionary<int, int>();
        var score = 0;
        var sum = 0;

        int i=0, j=0;
        while (j < nums.Length) {
            sum += nums[j];
            if (dict.ContainsKey(nums[j])) dict[nums[j]]++;
            else dict[nums[j]] = 1;

            while (dict[nums[j]] > 1) {
                dict[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            j++;

            score = Math.Max(score, sum);
        }

        return score;
    }
}