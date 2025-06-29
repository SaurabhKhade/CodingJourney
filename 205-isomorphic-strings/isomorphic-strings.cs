public class Solution {
    public bool IsIsomorphic(string s, string t) {
        var dict = new Dictionary<char, char>();
        var mapped = new Dictionary<char, bool>();

        for (int i=0; i<s.Length; i++) {
            if (dict.ContainsKey(t[i]) && dict[t[i]] != s[i]) return false;

            if (!dict.ContainsKey(t[i]) && mapped.ContainsKey(s[i])) return false;

            mapped[s[i]] = true;
            dict[t[i]] = s[i];
        }

        return true;
    }
}