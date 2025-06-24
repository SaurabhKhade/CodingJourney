public class Solution {
    public IList<int> FindKDistantIndices(int[] nums, int key, int k) {
        var keyIndices = new List<int>();
        for (int i=0; i<nums.Count(); i++) {
            if (nums[i] == key) {
                keyIndices.Add(i);
            }
        }

        var result = new List<int>();
        int j=0;

        for (int i=0; i<nums.Count() && j<keyIndices.Count(); i++) {
            if (Math.Abs(keyIndices[j] - i) <= k) {
                result.Add(i);
            }
            else if (i > keyIndices[j]) {
                j++;
                i--;
            }
        }

        return result;
    }
}