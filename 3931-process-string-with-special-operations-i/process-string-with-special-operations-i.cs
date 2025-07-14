public class Solution {
    public string ProcessStr(string s) {
        var builder = new StringBuilder();

        foreach (var chr in s) {
            switch (chr){
                case '*':
                    if (builder.Length > 0) {
                        builder.Length--;
                    }
                    break;
                case '#':
                    builder.Append(builder.ToString());
                    break;
                case '%':
                    var str = builder.ToString();
                    builder = new StringBuilder(string.Join(string.Empty, str.Reverse()));
                    break;
                default:
                    builder.Append(chr);
                    break;
            }
        }

        return builder.ToString();
    }
}