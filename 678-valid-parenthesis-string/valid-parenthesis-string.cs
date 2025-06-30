public class Solution {
    public bool CheckValidString(string s) {
        int stars = 0, open = 0;
        for (int i = 0; i<s.Length; i++) {
            if (s[i] == '*') stars++;
            else if (s[i] == '(') open++;
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
    }
}