class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = reduce(nums.begin(), nums.end(), 0);
        int take, skip;
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        vector<int> prev(sum+1), next(sum+1);

        prev[0] = 1;
        if (nums[0] <= sum) prev[nums[0]] = 1;
        if (nums[0] == 0) prev[0] = 2;

        for (int i=1; i<n; i++) {
            for (int j=0; j<=sum; j++) {
                skip = prev[j];
                take = (j >= nums[i]) ? prev[j-nums[i]] : 0;
                next[j] = skip + take;
            }
            prev = next;
        }

        int cnt = 0;
        for (int i=0; i<=sum; i++) {
            if ((2*i - sum) == abs(target)) {
                cnt += prev[i];
            }
        }

        return cnt;
        // vector<unordered_map<int,int>> dp(n, unordered_map<int,int>());
        // return helper(nums, target, n-1, dp);
    }

    // recursive memoization
    int helper(vector<int> &nums, int target, int ind, vector<unordered_map<int,int>> &dp) {
        if (ind == 0) {
            if (target == 0 && nums[ind] == 0) return 2;
            return (nums[ind] == abs(target));
        }
        else if (dp[ind].find(target) != dp[ind].end()) {
            return dp[ind][target];
        }

        int negCounts = helper(nums, target - nums[ind], ind-1, dp);
        int posCounts = helper(nums, target + nums[ind], ind-1, dp);

        return dp[ind][target] = negCounts + posCounts;
    }
};
