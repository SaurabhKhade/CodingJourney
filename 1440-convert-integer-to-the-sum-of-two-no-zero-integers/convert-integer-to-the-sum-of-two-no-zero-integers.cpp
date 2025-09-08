class Solution {
public:
    inline bool isNonZero(int n) {
        while (n > 0) {
            if (n%10 == 0) return false;
            n /= 10;
        }

        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i=1; i<=n/2; i++) {
            if (isNonZero(i) && isNonZero(n-i)) {
                return { i, n-i };
            }
        }

        return { -1, -1 };
    }
};