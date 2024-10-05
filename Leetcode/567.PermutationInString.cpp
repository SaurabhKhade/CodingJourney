class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Cnt(26), s2Cnt(26);
        for (const char &i:s1) s1Cnt[i-'a']++;

        for (int i=0, j=0; j<s2.size(); j++) {
            s2Cnt[s2[j]-'a']++;

            while (s2Cnt[s2[j]-'a'] > s1Cnt[s2[j]-'a']) {
                s2Cnt[s2[i]-'a']--;
                i++;
            }

            if (isValid(s1Cnt, s2Cnt)) return true;
        }

        return false;
    }

    bool isValid(vector<int> &arr1, vector<int> &arr2) {
        for (int i=0; i<26; i++) {
            if (arr1[i] != arr2[i]) return false;
        }

        return true;
    }
};