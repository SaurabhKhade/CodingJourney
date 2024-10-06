class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int> (W+1, 0));
        vector<int> prev(W+1, 0), current(W+1, 0);
        int maxValue = 0;
        
        prev[0] = 0;
        for (int i=1; wt[0]*i <= W;i++) {
            prev[wt[0]*i] = val[0]*i;
            maxValue = max(maxValue, val[0]*i);
        }
        
        for (int i=1; i<N; i++) {
            for (int j=1; j<=W; j++) {
                int skip = prev[j];
                int take = (j-wt[i]) < 0 ? 0 : (current[j-wt[i]] + val[i]);
                current[j] = max(take, skip);
                maxValue = max(maxValue, current[j]);
            }
            prev = current;
        }
        
        return maxValue;
    }
};