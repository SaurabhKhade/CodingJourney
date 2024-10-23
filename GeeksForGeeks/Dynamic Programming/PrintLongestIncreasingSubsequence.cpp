class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> LIS(n), prevIndex(n);
        
        int maxi = INT_MIN, maxInd = 0;
        for (int i=0; i<n; i++) {
            prevIndex[i] = i;
            for (int j=0; j<i; j++) {
                if (arr[i] > arr[j] && LIS[j]+1 > LIS[i]) {
                    LIS[i] = 1+LIS[j];
                    prevIndex[i] = j;
                }
            }
            
            if (LIS[i] > maxi) {
                maxi = LIS[i];
                maxInd = i;
            }
        }
        
        vector<int> result;
        result.push_back(arr[maxInd]);
        while (maxInd != prevIndex[maxInd]) {
            maxInd = prevIndex[maxInd];
            result.push_back(arr[maxInd]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};