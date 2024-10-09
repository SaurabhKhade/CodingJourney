class Solution {
    const int LIMIT = 1e9+7;
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> prev(sum+1), next(sum+1);
        
        prev[0] = prev[arr[0]] = 1;
        if (arr[0] == 0) prev[0] = 2;
        
        for (int ind=1; ind<n; ind++) {
            for (int target = 0; target <= sum; target++) {
                int skip = prev[target];
                int take = (target >= arr[ind]) ? prev[target-arr[ind]] : false;
                next[target] = (skip + take)%LIMIT;
            }
            prev = next;
        }

        int cnt = 0;
        for (int i=0; i<=sum; i++) {
            if (2*i-sum == d) {
                cnt+=prev[i];
            }
        }
        
        return cnt;
    }
};