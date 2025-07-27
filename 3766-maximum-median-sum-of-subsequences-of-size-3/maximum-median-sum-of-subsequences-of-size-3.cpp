class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int i=0, j = nums.size()-1;
        sort(nums.begin(), nums.end());
        long long score = 0;
        while (i < j) {
            score += nums[j-1];
            i++;
            j -= 2;
        }

        return score;
    }
};
