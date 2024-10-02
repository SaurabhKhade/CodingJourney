class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size(), i=0, j, k;

        while (i < n-2) {
            j = i+1, k = n-1;
            while (j<k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    do j++; while (j<k && nums[j]==nums[j-1]);
                    do k--; while (j<k && nums[k]==nums[k+1]);
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }

            do {
                i++;
            } while (i < n-2 && nums[i] == nums[i-1]);
        }

        return result;
    }
};