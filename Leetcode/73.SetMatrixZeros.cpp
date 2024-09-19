class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> col_map, row_map;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    col_map[j] = true;
                    row_map[i] = true;
                }
            }
        }

        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (row_map[i] || col_map[j]) matrix[i][j] = 0;
            }
        }
    }
};