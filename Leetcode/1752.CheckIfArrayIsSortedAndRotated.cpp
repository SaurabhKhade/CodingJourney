class Solution {
public:
  bool check(vector<int>& nums) {
    int violationIndex = 0, n = nums.size();
    for (int i=1; i<n; i++) {
        if (nums[i] < nums[i-1]) {
            violationIndex = i;
            break;
        }
    }
    
    for (int i=(violationIndex+1)%n; i != violationIndex; i = (i+1)%n) {
        if (nums[i] < nums[(n+i-1)%n]) return false;
    }

    return true;
  }
};