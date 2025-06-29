public class Solution {
    public void Rotate(int[][] matrix) {
        int n = matrix.Length;
        for (int i = 0; i<n; i++) {
            for (int j =i+1; j<n; j++) {
                (matrix[i][j],matrix[j][i]) = (matrix[j][i],matrix[i][j]);
            }
        }

        for (int i=0; i<n; i++) {
            int l = 0, r = n-1;
            while (l < r) {
                (matrix[i][l],matrix[i][r]) = (matrix[i][r],matrix[i][l]);
                l++;
                r--;
            }
        }
    }
}