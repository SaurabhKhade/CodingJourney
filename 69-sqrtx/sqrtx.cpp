class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int low = 0, high = x/2;
        int result = 0;
        while (low <= high) {
            long mid = (low+high)/2;
            if (mid*mid <= x) {
                result = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return result;
    }
};