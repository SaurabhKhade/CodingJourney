public class Solution {
    public string MakeFancyString(string s) {
        if (s.Length < 3) return s;

        var builder = new StringBuilder(s.Substring(0, 2));
        int j=2;

        while (j < s.Length) {
            if (s[j] != s[j-1] || s[j] != s[j-2]) {
                builder.Append(s[j]);
            }
            j++;
        }

        return builder.ToString();
    }
}