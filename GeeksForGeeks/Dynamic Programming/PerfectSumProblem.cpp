class Solution{
  const int LIMIT = 1e9+7;
	public:
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum+1));
        vector<int> prev(sum+1), next(sum+1);
        
        if (arr[0] <= sum) prev[arr[0]] = 1;
        prev[0] = 1 + (arr[0] == 0);
        
        
        for (int i=1; i<n; i++) {
            for (int j=0; j<=sum; j++) {
                int skip =prev[j];
                int take = (arr[i]<=j) ? prev[j-arr[i]] : 0;
                next[j] = (skip + take)%LIMIT;
            }
            prev = next;
        }
        
        return prev[sum];
	  }
};