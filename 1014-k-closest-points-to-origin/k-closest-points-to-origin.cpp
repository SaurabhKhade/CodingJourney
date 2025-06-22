class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // for (auto v : points) {
        //     cout << v[0] << "," << v[1] << "  ";
        // }
        // cout << endl;

        sort(points.begin(), points.end(), [](auto a, auto b) {
            int dist1 = a[0] * a[0] + a[1] * a[1];
            int dist2 = b[0] * b[0] + b[1] * b[1];
            return dist2 > dist1;
        });

        // for (auto v : points) {
        //     cout << v[0] << "," << v[1] << "  ";
        // }
        // cout << endl;

        points.resize(k);
        return points;
    }
};