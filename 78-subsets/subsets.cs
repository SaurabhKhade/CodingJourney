public class Solution {
    public IList<IList<int>> Subsets(int[] nums) {
        var result = new List<IList<int>>();
        Helper(nums, 0, result, new List<int>());
        return result;
    }

    public static void Helper(int[] nums, int i, IList<IList<int>> result, IList<int> current) {
        // Console.WriteLine(i);
        if (i == nums.Length) {
            result.Add(new List<int>(current));
            return;
        }

        current.Add(nums[i]);
        Helper(nums, i+1, result, current);
        current.RemoveAt(current.Count - 1);
        Helper(nums, i+1, result, current);
    }
}