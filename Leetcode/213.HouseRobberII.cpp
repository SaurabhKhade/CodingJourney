class Solution {
    int lastHouseRobbed;
    unordered_map<int,int> map;
public:
    int rob(vector<int>& nums) {
        map.clear();
        lastHouseRobbed = 1;
        int money = helper(nums, nums.size()-1);

        lastHouseRobbed = 0;
        map.clear();
        money = max(money, helper(nums, nums.size()-2));
        money = max(money, helper(nums, nums.size()-3));

        return money;
    }

    int helper(vector<int>& nums, int n) {
        if (n <= 0) return nums[0];
        if (map.find(n) != map.end()) return map[n];

        int money = 0;
        for (int i = n-2; i>=lastHouseRobbed; i--) {
            money = max(money, helper(nums, i));
        }

        return map[n] = money + nums[n];
    }
};