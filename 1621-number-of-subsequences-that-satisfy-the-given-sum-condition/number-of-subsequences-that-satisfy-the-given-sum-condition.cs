public class Solution {
    const int LIMIT = (int)(1e9+7);
    public int NumSubseq(int[] nums, int target) {
        Array.Sort(nums);
        long ways = 0;

        var pows = new int [nums.Length];
        pows[0] = 1;
        for(int i=1;i<nums.Length;i++){
            pows[i] = (pows[i-1] * 2) % LIMIT;
        }

        // Console.WriteLine(LIMIT);

        for (int i=0; i<nums.Length; i++) {
            if (nums[i]*2 > target) break;

            int j = i, left = i, right = nums.Length-1;

            while (left <= right) {
                int mid = ((left+right)/2);

                if (nums[mid] + nums[i] <= target) {
                    j = mid;
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }


            ways = (ways + pows[j-i])%LIMIT;
        }

        return (int)ways;
    }
}
