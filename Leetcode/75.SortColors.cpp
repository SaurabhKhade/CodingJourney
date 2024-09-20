class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, mid = 0, right = nums.size()-1, t;
        while (mid <= right) {
            if (nums[mid] == 0) {
                t = nums[mid];
                nums[mid] = nums[left];
                nums[left] = t;
                left++;
                mid++;
            } else if (nums[mid] == 2) {
                t = nums[mid];
                nums[mid] = nums[right];
                nums[right] = t;
                right--;
            } else mid ++;
        }
    }
};