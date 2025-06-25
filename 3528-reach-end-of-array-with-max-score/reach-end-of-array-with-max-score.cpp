class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        int i = 0, curr = nums[0];
        long long score = 0;

        for (int j=1; j<n; j++) {
            if (nums[j] > nums[i]) {
                score += (long long)(j-i)* nums[i];
                i = j;
            }
        }

        return score + (long long)(n-i-1)* nums[i];
    }
};

