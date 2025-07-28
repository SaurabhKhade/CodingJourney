class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int i: nums) {
            maxOr |= i;
        }

        return helper(nums, maxOr, 0, 0);
    }

    int helper(vector<int>& nums, int target, int runOr, int i) {
        if (i == nums.size()) {
            return target == runOr;
        }

        return helper(nums, target, runOr | nums[i], i+1) +
                helper(nums, target, runOr, i+1);
    }
};
