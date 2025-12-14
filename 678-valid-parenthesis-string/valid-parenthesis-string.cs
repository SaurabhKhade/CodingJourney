public class Solution {
    public bool CheckValidString(string s) {
        Stack<int> stars = new Stack<int>(), opens = new Stack<int>();

        for (int i=0; i<s.Length; i++) {
            if (s[i] == '(') {
                opens.Push(i);
            }
            else if (s[i] == '*') {
                stars.Push(i);
            }
            else if (opens.Count > 0) {
                opens.Pop();
            }
            else if (stars.Count > 0) {
                stars.Pop();
            }
            else {
                return false;
            }
        }

        while (opens.Count > 0) {
            if (stars.Count == 0 || stars.Peek() < opens.Peek()) {
                return false;
            }

            stars.Pop();
            opens.Pop();
        }

        return true;
    }
}


