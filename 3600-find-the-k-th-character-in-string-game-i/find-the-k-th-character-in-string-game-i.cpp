class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            s = nextString(s);
        }

        return s[k-1];
    }
    string nextString(string s) {
        string ss = s;
        for (char &chr : s) {
            ss += 'a' + (((chr - 'a') + 1)%26);
        }
        return ss;
    }
};