class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        array<int, 58> map;
        for (const char &chr: t) map[chr-'A']--;
        int miniSize = INT_MAX, miniStart;

        for (int i=0,j=0; j<s.size(); j++) {
            map[s[j]-'A']++;

            if (isIncluded(map)) {
                while (isIncluded(map)) {
                    map[s[i]-'A']--;
                    i++;
                }

                if (j-i+2 < miniSize) {
                    miniSize = j-i+2;
                    miniStart = i-1;
                }
            }
        }

        return miniSize == INT_MAX ? "" : s.substr(miniStart, miniSize);
    }

    bool isIncluded(array<int, 58> &arr) {
        for (const int &i: arr) {
            if (i<0) return false;
        }

        return true;
    }
};