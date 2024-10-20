class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int result = 0;

        for (int i=0; i<n; i++) {
            vector<int> cnt(26);
            for (int j=i; j<n; j++) {
                cnt[s[j]-'a']++;
                if (atLeastK(cnt, k)) {
                    result += n-j;
                    break;
                }
            }
        }

        return result;
    }

    bool atLeastK(vector<int> &cnt, int k) {
        for (int i=0; i<26; i++) {
            if (cnt[i] == k) return true;
        }
        return false;
    }
};