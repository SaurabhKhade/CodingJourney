class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 5) return 0;
        sort(nums.begin(), nums.end());

        // 3 from start 0 from end
        int minDiff = nums[n-1] - nums[3];

        // 2 from start 1 from end
        minDiff = min(minDiff, nums[n-2] - nums[2]);

        // 1 from start 2 from end
        minDiff = min(minDiff, nums[n-3] - nums[1]);

        // 0 from start 3 from end
        return min(minDiff, nums[n-4] - nums[0]);
    }
};