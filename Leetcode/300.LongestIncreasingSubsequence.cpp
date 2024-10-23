class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);

        int maxi = INT_MIN;
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j] && LIS[j]+1 > LIS[i]) {
                    LIS[i] = 1+LIS[j];
                }
            }
            
            if (LIS[i] > maxi) {
                maxi = LIS[i];
            }
        }
        
        return maxi;
    }
};