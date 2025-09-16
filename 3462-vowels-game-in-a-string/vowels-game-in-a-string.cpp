class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels = 0;
        bool map[26];

        map[0] = map['e'-'a'] = map['i'-'a'] = map['o'-'a'] = map['u'-'a'] = true;

        for (char chr : s) if (map[chr-'a']) return true;

        return false;
    }
};