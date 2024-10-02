class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size(), i=0, j, k, l;

        while (i < n-3) {
            j = i+1;
            while (j < n-2) {
                k = j+1, l = n-1;
                while (k < l) {
                    if ((long)nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        do k++; while (k<l && nums[k]==nums[k-1]);
                        do l--; while (k<l && nums[l]==nums[l+1]);
                    }
                    else if ((long)nums[i] + nums[j] + nums[k] + nums[l] > target) {
                        l--;
                    }
                    else {
                        k++;
                    }
                }

                do {
                    j++;
                } while (j < n-2 && nums[j] == nums[j-1]);
            }

            do {
                i++;
            } while (i < n-3 && nums[i] == nums[i-1]);
        }

        return result;
    }
};