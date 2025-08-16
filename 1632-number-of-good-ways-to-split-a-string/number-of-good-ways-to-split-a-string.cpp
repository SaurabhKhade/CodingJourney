class Solution {
public:
    int numSplits(string s) {
        vector<int> left(26), right(26);
        for (char chr : s) {
            right[chr-'a']++;
        }

        auto isEqual = [&left, &right]() -> bool {
            int leftDist = 0, rightDist = 0;
            for (int i:left) if (i > 0) leftDist++;
            for (int i:right) if (i > 0) rightDist++;

            return leftDist == rightDist;
        };

        int result = 0;

        for (char chr: s) {
            left[chr-'a']++;
            right[chr-'a']--;

            result += isEqual();
        }

        return result;
    }
};