public class Solution {
    public string CountAndSay(int n) {
        return Helper(n-1, "1");
    }

    public static string Helper(int n, string current) {
        if (n == 0) return current;

        var builder = new StringBuilder();
        int i=0, j=1;
        char chr = current[0];
        while (j < current.Length) {
            if (current[j] != current[i]) {
                builder.Append(j-i);
                builder.Append(chr);
                chr = current[j];
                i = j;
            }
            j++;
        }
        builder.Append(j-i);
        builder.Append(chr);

        return Helper(n-1, builder.ToString());
    }
}