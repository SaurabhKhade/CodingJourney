class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_map<int, bool> map;
        int sum = 0;
        for (int i : nums) {
            map[i] = true;
            sum += i;
        }

        int start = max(sum / (int)nums.size() + 1, 1);
        while (map[start]) start++;
        return start;
    }
};