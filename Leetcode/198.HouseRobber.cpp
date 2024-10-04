class Solution {
    unordered_map<int,int> map;
public:
    int rob(vector<int>& nums) {
        map.clear();
        return max(helper(nums, nums.size()-1), helper(nums, nums.size()-2));
    }

    int helper(vector<int>& nums, int n) {
        if (n <= 0) return nums[0];
        if (map.find(n) != map.end()) return map[n];

        int money = 0;
        for (int i = n-2; i>=0; i--) {
            money = max(money, helper(nums, i));
        }

        return map[n] = money + nums[n];
    }
};