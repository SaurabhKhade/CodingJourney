class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> map;
        int score = 0, sum = 0, i = 0, j = 0, n = nums.size();

        while (j < n) {
            map[nums[j]]++;
            sum += nums[j];
            while (map[nums[j]] > 1) {
                map[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            j++;

            score = max(sum, score);
        }

        return score;
    }
};