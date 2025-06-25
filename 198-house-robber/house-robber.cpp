class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> vec(nums.size(), -1);
        return max(helper(nums, 0, vec), helper(nums, 1, vec));
    }

    int helper(vector<int>& nums, int n, vector<int> &vec) {
        if (n >= nums.size()) return 0;
        if (vec[n] != -1) return vec[n];

        return vec[n] = max(helper(nums, n+2, vec) + nums[n], helper(nums, n+1, vec));

        // if (n <= 0) return nums[0];
        // if (map.find(n) != map.end()) return map[n];

        // int money = 0;
        // for (int i = n-2; i>=0; i--) {
        //     money = max(money, helper(nums, i));
        // }

        // return map[n] = money + nums[n];
    }
};