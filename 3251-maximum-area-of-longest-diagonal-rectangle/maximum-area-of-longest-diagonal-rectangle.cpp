class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0, diag = 0;
        for (auto &rect : dimensions) {
            int d = rect[0]*rect[0] + rect[1]*rect[1];
            if (d == diag) {
                area = max(area, rect[0]*rect[1]);
            }
            else if (d > diag) {
                diag = d;
                area = rect[0]*rect[1];
            }
        }

        return area;
    }
};