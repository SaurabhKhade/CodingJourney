public class Solution {
    public IList<string> LetterCombinations(string digits) {
        var result = new List<string>();
        var digitMap = new Dictionary<char, string> {
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" }
        };

        Helper(0, digits, string.Empty, result, digitMap);

        return result;
    }

    void Helper(int ind, string digits, string str, IList<string> result, IDictionary<char, string> mappings) {
        if (ind == digits.Length) {
            if (str.Length != 0) result.Add(str);
            return;
        }

        foreach (var chr in mappings[digits[ind]]) {
            Helper(ind+1, digits, str+chr, result, mappings);
        }
    }
}