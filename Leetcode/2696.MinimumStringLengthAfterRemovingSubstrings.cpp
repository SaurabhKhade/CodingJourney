class Solution {
public:
    int minLength(string s) {
        stack<char> stack;
        for (const char &c:s) {
            if (c != 'B' && c != 'D') {
                stack.push(c);
            } else if (stack.empty()) {
                stack.push(c);
            } else {
                if ((c == 'B' && stack.top() == 'A') || (c == 'D' && stack.top() == 'C')) stack.pop();
                else stack.push(c);
            }
        }

        return stack.size();
    }
};