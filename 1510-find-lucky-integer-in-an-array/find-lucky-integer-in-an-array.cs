public class Solution {
    public int FindLucky(int[] arr) {
        var dict = new Dictionary<int, int>();
        foreach (var el in arr) {
            if (dict.ContainsKey(el)) dict[el]++;
            else dict[el] = 1;
        }

        int max = -1;

        foreach (var entry in dict) {
            if (entry.Key == entry.Value) {
                max = Math.Max(max, entry.Key);
            }
        }

        return max;
    }
}