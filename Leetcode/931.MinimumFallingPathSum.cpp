class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), min;
        for (int i=1; i<n; i++) {
            for (int j=0; j<n; j++) {
                min = INT_MAX;
                for (int k=-1; k<=1; k++) {
                    if ((j+k)>=0 && (j+k)<n && matrix[i-1][j+k] < min) {
                        min = matrix[i-1][j+k];
                    }
                }
                matrix[i][j] += min;
            }
        }

        min = INT_MAX;
        for (const int &a: matrix.back()) {
            min = min < a ? min : a;
        }

        return min;
    }
};