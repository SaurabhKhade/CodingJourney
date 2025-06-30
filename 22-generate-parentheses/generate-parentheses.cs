public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        var list = new List<string>();
        Helper(n, 0, 0, "", list);
        return list;
    }

    void Helper(int n, int open, int close, string curr, List<string> result) {
        if (open == n && open == close) {
            result.Add(curr);
            return;
        }

        if (open < n) {
            Helper(n, open+1, close, curr+'(', result);
        }
        if (open > close) {
            Helper(n, open, close+1, curr+')', result);
        }
    }
}