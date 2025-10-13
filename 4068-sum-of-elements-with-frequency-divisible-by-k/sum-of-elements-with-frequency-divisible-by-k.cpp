class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int el : nums) {
            map[el]++;
        }

        int sum = 0;

        for (auto [el, freq] : map) {
            if (freq % k == 0) {
                sum += el*freq;
            }
        }

        return sum;
    }
};