class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] <= 0) {
                nums[i] = INT_MAX;
            }
        }

        for (int i=0; i<nums.size(); i++) {
            int value = abs(nums[i]);
            if (value <= nums.size()) {
                nums[value-1] = -1 * abs(nums[value-1]);
            }
        }

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }

        return nums.size() + 1;      
    }
};