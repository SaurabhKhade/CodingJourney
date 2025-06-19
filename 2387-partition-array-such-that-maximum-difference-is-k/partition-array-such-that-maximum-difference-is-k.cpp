class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = 1, i = 0, j = 1;

        while (j < nums.size()) {
            if (nums[j]-nums[i] > k) {
                n++;
                i = j;
            }
            j++;
        }

        return n;
    }
};
