class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<bool> used(n);
        helper(nums, {}, used, result);

        return result;
    }

    void helper(vector<int> &nums, vector<int> current, vector<bool> &used, vector<vector<int>> &result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                current.push_back(nums[i]);
                helper(nums, current, used, result);
                used[i] = false;
                current.pop_back();
            }
        }
    }
};
