class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i: nums) map[i]++;

        int sum = 0, max = 0;

        for (auto [key, val] : map) {
            // cout<<key<<" "<<val<<endl;
            if (val > max) {
                max = val;
                sum = val;
            }
            else if (val == max) {
                sum += val;
            }
        }

        return sum;
    }
};