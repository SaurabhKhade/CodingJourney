public class Solution {
    public bool CheckValidString(string s) {
        int stars = 0, open = 0;
        foreach (var chr in s) {
            if (chr == '*') stars++;
            else if (chr == '(') open++;
            else {
                open--;
                if (open < 0 && stars == 0) return false;
                if (open < 0) {
                    open = 0;
                    stars--;
                }
            }
        }

        stars = 0;
        open = 0;
        
        for (int i = s.Length - 1; i>=0; i--) {
            if (s[i] == '*') stars++;
            else if (s[i] == ')') open++;
            else {
                open--;
                if (open < 0 && stars == 0) return false;
                if (open < 0) {
                    open = 0;
                    stars--;
                }
            }
        }

        return true;

        // if (open > stars) return false;

        // var curr = open;
        // stars = 0;
        // int i = s.Length-1;

        // while (i >= 0 && curr > 0) {
        //     if (s[i] == '(') curr--;
        //     else if (s[i] == '*') stars++;
        //     i--;
        // }

        // return open <= stars;
    }
}