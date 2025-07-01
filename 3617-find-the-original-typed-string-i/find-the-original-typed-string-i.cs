public class Solution {
    public int PossibleStringCount(string word) {
        int i=0, j = 0, possibilities = 0;
        while (j<word.Length) {
            while (j<word.Length && word[j] == word[i]) {
                j++;
            }
            // Console.WriteLine($"{j} & {i}");
            possibilities += (j-i-1);
            i = j;
        }

        return possibilities + 1;
    }
}
