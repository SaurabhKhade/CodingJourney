class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i=1; i<triangle.size(); i++) {
            triangle[i][0] += triangle[i-1][0];
            for (int j=1; j<triangle[i].size()-1; j++) {
                triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
            triangle[i].back() += triangle[i-1].back();
        }

        return reduce(triangle.back().begin(), triangle.back().end(), INT_MAX, [](int a, int b) {
            return a < b ? a : b;
        });
    }
};