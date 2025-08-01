public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        var triangle = new List<IList<int>> {
            new List<int> { 1 }
        };
        
        for (int i=1; i<numRows; i++) {
            var nextRow = new List<int> { 1 };
            for (int j = 1; j < i; j++) {
                nextRow.Add(triangle[i-1][j] + triangle[i-1][j-1]);
            }
            nextRow.Add(1);
            triangle.Add(nextRow);
        }

        return triangle;
    }
}