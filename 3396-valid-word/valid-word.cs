public class Solution {
    public bool IsValid(string word) {
        if (word.Length < 3) return false;
        bool vowel = false, consonent = false;
        char[] vowels = new char[] { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

        foreach (var chr in word) {
            if (!(chr >= '0' && chr <= '9') && !(chr >= 'a' && chr <= 'z') && !(chr >= 'A' && chr <= 'Z')) {
                return false;
            }
            if (vowels.Contains(chr)) {
                vowel = true;
            }
            else if (!(chr >= '0' && chr <= '9')) {
                consonent = true;
            }
        }

        return vowel && consonent;
    }
}