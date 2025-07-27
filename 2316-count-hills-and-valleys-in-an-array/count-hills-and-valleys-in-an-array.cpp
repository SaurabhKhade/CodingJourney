class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i=0, j=1;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
            j++;
        }

        int count = 0;
        for (int k=1; k<i; k++) {
            if (nums[k] > nums[k-1] && nums[k] > nums[k+1]) {
                count++;
            }
            else if (nums[k] < nums[k-1] && nums[k] < nums[k+1]) {
                count++;
            }
        }

        return count;
    }
};