public class Solution {
    public int[] MaxSubsequence(int[] nums, int k) {
        var elements = new List<(int, int)>();

        for(int i=0; i<nums.Length; i++) {
            elements.Add((nums[i], i));
        }

        elements.Sort((x, y) => y.Item1.CompareTo(x.Item1));

        List<(int, int)> topK = new List<(int, int)>();

        for (int j = 0; j < k; j++)
        {
            topK.Add(elements[j]);
        }

        topK.Sort((x, y) => x.Item2.CompareTo(y.Item2));

        var result = new int[k];
        for (int i=0; i<k; i++) {
            result[i] = topK[i].Item1;
        }

        return result;
    }
}