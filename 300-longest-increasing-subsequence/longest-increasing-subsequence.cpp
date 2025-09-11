class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vec(n+1, vector<int>(n+1, -1));

        return LIS(nums, 0, -1, vec);
    }

    int LIS(vector<int>& nums, int i, int pi, vector<vector<int>> &vec) {
        if (i == nums.size()) return 0;
        if (vec[i][pi+1] != -1) return vec[i][pi+1];

        if (pi != -1 && nums[i] <= nums[pi]) {
            return vec[i][pi+1] = LIS(nums, i+1, pi, vec);
        } else {
            int take = LIS(nums, i+1, i, vec)+1;
            int skip = LIS(nums, i+1, pi, vec);
            return vec[i][pi+1] = max(take, skip);
        }
    }
};