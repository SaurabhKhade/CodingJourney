public class Solution {
    public int[][] Construct2DArray(int[] original, int m, int n) {
        if (original.Length != m*n) return new int[0][];

        var result = new int[m][];
        int k=0;
        
        for (int i=0; i<m; i++) {
            result[i] = new int[n];
            for (int j=0; j<n; j++) {
                result[i][j] = original[k++];
            }
        }

        return result;
    }
}