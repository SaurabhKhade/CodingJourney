class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0, len = 0;
        for (int &i:nums) {
            if (i == 1) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 0;
            }
        }
        return max(maxLen, len);
    }
};