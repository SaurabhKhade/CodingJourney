class Solution {
public:
    double myPow(double x, int n) {
        int nn = abs(n);
        double ans = 1;
        while(nn) {
            if (nn%2 == 1) {
                ans *= x;
                nn--;
            } else {
                x *= x;
                nn /= 2;
            }
        }

        return n < 0 ? 1 / ans : ans;
    }
};