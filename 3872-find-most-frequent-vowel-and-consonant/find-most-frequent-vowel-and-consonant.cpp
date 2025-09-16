class Solution {
public:
    int maxFreqSum(string s) {
        bool map[26];
        int vowels[26], consos[26];
        int vowFr = 0, conFr = 0;

        map[0] = map['e'-'a'] = map['i'-'a'] = map['o'-'a'] = map['u'-'a'] = true;

        for (char chr : s) {
            int ind = chr-'a';
            if (map[ind]) {
                vowels[ind]++;
                vowFr = max(vowFr, vowels[ind]);
            } else {
                consos[ind]++;
                conFr = max(conFr, consos[ind]);
            }
        }

        return conFr + vowFr;
    }
};