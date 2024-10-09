class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, open = 0;
        for (const char &c:s) {
            if (c == '(') open++;
            else if (open == 0) cnt++;
            else open--;
        }

        return cnt+open;
    }
};