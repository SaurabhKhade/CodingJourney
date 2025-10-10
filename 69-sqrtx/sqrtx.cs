public class Solution {
    public int MySqrt(int x) {
        if (x == 0) return 0;
        int low = 1, high = x/2;
        int sqrt = 1;
        
        while (low <= high) {
            int mid = low + (high - low)/2;

            if (x/mid == mid) {
                return mid;
            }
            else if (x/mid < mid) {
                high = mid-1;
            }
            else {
                low = mid+1;
                sqrt = mid;
            }
        }

        return sqrt;
    }
}

// 8
// 2

// 3 2
// 3
