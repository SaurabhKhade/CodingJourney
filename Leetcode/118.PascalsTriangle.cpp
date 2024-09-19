class Solution {
    public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows, vector<int>());
        result[0] = { 1 };

        for (int i=1; i<numRows; i++) {
            result[i].push_back(result[i-1][0]);
            for (int j=1; j<i; j++) {
                result[i].push_back(result[i-1][j] + result[i-1][j-1]);
            }
            result[i].push_back(result[i-1][i-1]);
        }

        return result;
    }
};