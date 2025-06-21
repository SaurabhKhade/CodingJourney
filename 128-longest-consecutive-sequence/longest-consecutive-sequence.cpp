class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        for (const int i: nums) set.insert(i);

        int result = 0;

        for (int i: set) {
            if (set.find(i-1) != set.end()) continue;

            int length = 0;
            while (set.find(i) != set.end()) {
                length++;
                i++;
            }

            result = max(result, length);
        }

        return result;
    }
};
