class Solution {
  public:
    int pairWithMaxSum(vector<int> &arr) {
        int mx = 0;
        for (int i=1; i<arr.size(); i++) {
            mx = max(mx, arr[i] + arr[i-1]);
        }
        return mx;
    }
};