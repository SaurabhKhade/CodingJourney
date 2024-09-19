class Solution {
    public:
    int print2largest(vector<int> &arr) {
        int mx1 = INT_MIN, mx2 = INT_MIN;
        
        for (auto &i:arr) {
            if (i > mx1) {
                mx2 = mx1;
                mx1 = i;
            } else if (i > mx2 && i < mx1) {
                mx2 = i;
            }
        }
        
        return mx2 == INT_MIN ? -1 : mx2;
    }
};