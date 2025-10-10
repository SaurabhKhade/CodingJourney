public class Solution {
    public string IntToRoman(int num) {
        var digit = new string[] { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        var value = new int[] {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        int i = 0;
        var roman = new StringBuilder();

        while (num > 0) {
            while (num < value[i]) i++;
            roman.Append(digit[i]);
            num -= value[i];
        }

        return roman.ToString();
    }
}
