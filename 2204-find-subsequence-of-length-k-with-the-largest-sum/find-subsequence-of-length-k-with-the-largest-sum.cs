public class Solution {
    public int[] MaxSubsequence(int[] nums, int k) {
        var elements = new List<(int, int)>();

        for(int i=0; i<nums.Length; i++) {
            elements.Add((nums[i], i));
        }

        elements.Sort((x, y) => y.Item1.CompareTo(x.Item1));

        elements = elements.Take(k).ToList();

        elements.Sort((x, y) => x.Item2.CompareTo(y.Item2));

        var result = new int[k];
        for (int i=0; i<k; i++) {
            result[i] = elements[i].Item1;
        }

        return result;
    }
}