class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = reduce(nums.begin(), nums.end(), 0);
        if (sum%2==1) return false;

        vector<bool> prev(sum+1), current(sum+1);

        prev[sum/2] = true;

        for (int i=1; i<n; i++) {
            for (int j=1; j<=sum; j++) {
                bool skip = prev[j];
                bool take = j-nums[i] < 0 ? false : prev[j-nums[i]];

                current[j] = take | skip;
            }
            prev = current;
        }
        
        return current[sum];
    }
};
