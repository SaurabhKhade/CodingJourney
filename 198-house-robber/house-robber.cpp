class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> vec(nums.size(), -1);
        return helper(nums, 0, vec);
    }

    int helper(vector<int>& nums, int n, vector<int> &vec) {
        if (n >= nums.size()) return 0;
        if (vec[n] != -1) return vec[n];

        return vec[n] = max(helper(nums, n+2, vec) + nums[n], helper(nums, n+1, vec));
    }
};