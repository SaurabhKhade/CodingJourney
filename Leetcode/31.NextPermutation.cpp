class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i1 = -1;
        for (int i=nums.size()-1; i>0; i--) {
            if (nums[i] > nums[i-1]) {
                i1 = i-1;
                break;
            }
        }

        if (i1 == -1) reverse(nums.begin(), nums.end());
        else {
            int i2 = -1;
            for (int i=nums.size()-1; i>i1; i--) {
                if (i2 == -1 && nums[i] > nums[i1]) i2 = i;
                if (nums[i] > nums[i1] && nums[i] < nums[i2]) i2 = i;
            }
            int t = nums[i1];
            nums[i1] = nums[i2];
            nums[i2] = t;

            reverse(nums.begin()+i1+1, nums.end());
        }
    }
};