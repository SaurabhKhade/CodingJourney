public class Solution {
    private static readonly string[] Symbols = 
        { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
    private static readonly int[] Values = 
        {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    public string IntToRoman(int num) {
        int i = 0;
        var roman = new StringBuilder();

        while (num > 0) {
            while (num < Values[i]) i++;
            roman.Append(Symbols[i]);
            num -= Values[i];
        }

        return roman.ToString();
    }
}
