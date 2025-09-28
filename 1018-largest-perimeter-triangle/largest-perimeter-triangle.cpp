class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=n-1; i>1; i--) {
            for (int j=i-1; j>0; j--) {
                if (nums[j] + nums[j-1] > nums[i]) {
                    return nums[i] + nums[j] + nums[j-1];
                }
            }
        }

        return 0;
    }
};
