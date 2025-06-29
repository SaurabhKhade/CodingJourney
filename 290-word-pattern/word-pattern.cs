public class Solution {
    public bool WordPattern(string pattern, string s) {
        var words = s.Split(' ');
        if (words.Length != pattern.Length) return false;

        var dict = new Dictionary<char, string>();
        var dict2 = new Dictionary<string, char>();

        for (int i=0; i<pattern.Length; i++) {
            if (dict.ContainsKey(pattern[i]) && dict[pattern[i]] != words[i]) return false;
            if (dict2.ContainsKey(words[i]) && dict2[words[i]] != pattern[i]) return false;
            dict[pattern[i]] = words[i];
            dict2[words[i]] = pattern[i];
        }

        return true;
    }
}