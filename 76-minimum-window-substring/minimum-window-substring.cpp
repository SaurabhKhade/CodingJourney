class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 58> map;
        for (const char &chr: t) map[chr-'A']--;
        string mini = "";
        int miniSize = INT_MAX;

        for (int i=0,j=0; j<s.size(); j++) {
            map[s[j]-'A']++;

            if (isIncluded(map)) {
                while (isIncluded(map)) {
                    map[s[i]-'A']--;
                    i++;
                }

                if (j-i+2 < miniSize) {
                    miniSize = j-i+2;
                    mini = s.substr(i-1, miniSize);
                }
            }
        }

        return mini;
    }

    bool isIncluded(array<int, 58> &arr) {
        for (const int &i: arr) {
            if (i<0) return false;
        }

        return true;
    }
};