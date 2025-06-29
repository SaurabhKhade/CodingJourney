public class Solution {
    public string Convert(string s, int numRows) {
        var array = new char[numRows, 1001];


        int i =0, j=0, k=0;
        while (k < s.Length) {
            i = 0;
            while (k < s.Length && i<numRows) {
                array[i, j] = s[k];
                k++;
                i++;
            }
            i = numRows - 2;
            j++;
            while (k < s.Length && i > 0) {
                array[i, j] = s[k];
                i--;
                j++;
                k++;
            }
        }

        var builder = new StringBuilder(s.Length);
        k =0;

        for (var row=0; row<numRows; row++) {
            for (var column = 0; column <= j; column++) {
                if (array[row, column] != '\0') {
                    builder.Append(array[row, column]);
                    k++;

                    if (k == s.Length) {
                        return builder.ToString();
                    }
                }
            }
        }

        return builder.ToString();
    }
}