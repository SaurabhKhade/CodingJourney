public class Solution {
    public int RomanToInt(string s) {
        var dict = new Dictionary<char, int> {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int value = 0;

        for (int i=0; i<s.Length; i++) {
            if (i+1 < s.Length && dict[s[i]] < dict[s[i+1]]) {
                value -= dict[s[i]];
            }
            else {
                value += dict[s[i]];
            }
        }

        return value;
    }
}