public class Solution {
    public IList<string> RestoreIpAddresses(string s) {
        var current = new int[4];
        var result = new List<string>();

        Helper(s, 0, 0, current, result);

        return result;
    }

    public static void Helper(string s, int i, int count, int[] current, IList<string> result) {
        // Console.WriteLine($"{i}, {count}");
        if (i == s.Length && count == 4) {
            result.Add(string.Join('.', current));
        }
        if (i == s.Length || count == 4) {
            return;
        }

        if (s[i] == '0') {
            current[count] = 0;
            Helper(s, i+1, count+1, current, result);
        }
        else {
            var num = 0;
            while (i < s.Length && num*10 + (s[i]-'0') <= 255) {
                num = num*10 + (s[i]-'0');
                i++;
                current[count] = num;
                Helper(s, i, count+1, current, result);
            }
        }
    }
}