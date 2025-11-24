class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result(nums.size());
        int value = 0;

        for (int i = 0; i<nums.size(); i++) {
            value =  (value * 2 + nums[i]) % 5;
            result[i] = value % 5 == 0;
        }

        return result;
    }
};


// 1 1 0 0 0 1 0 0 1
// F F F F F F F F F

// 1 0 0 1 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 0 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 1
// F F F F F F F F F F F F F F F F F F F F F F F F F T F F F F F F F F F F F F F

