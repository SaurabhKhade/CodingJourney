class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& pts) {
        double area = 0;
        int n = pts.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if ((pts[i][0] != pts[j][0] || pts[i][0] != pts[k][0])
                        && (pts[i][1] != pts[j][1] || pts[i][1] != pts[k][1])) {
                            double a = sqrt((pts[i][0] - pts[j][0]) * (pts[i][0] - pts[j][0]) + (pts[i][1] - pts[j][1]) * (pts[i][1] - pts[j][1]));
                            double b = sqrt((pts[j][0] - pts[k][0]) * (pts[j][0] - pts[k][0]) + (pts[j][1] - pts[k][1]) * (pts[j][1] - pts[k][1]));
                            double c = sqrt((pts[i][0] - pts[k][0]) * (pts[i][0] - pts[k][0]) + (pts[i][1] - pts[k][1]) * (pts[i][1] - pts[k][1]));
                            double s = (a+b+c)/2;
                            double ar = sqrt(s * (s-a) * (s-b) * (s-c));

                            area = max(area, ar); 
                        }
                }
            }
        }

        return area;
    }
};