class Solution {
    unordered_map<int, long long> map;
    const int LIMIT = 1e9 + 7;
  public:
    long long int topDown(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (map.find(n) != map.end()) return map[n];
        return map[n] = (topDown(n-1) + topDown(n-2))%LIMIT;
    }
    long long int bottomUp(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        long long a = 0, b = 1, c;
        for (int i=2; i<=n; i++) {
            c = (a + b)%LIMIT;
            a = b;
            b = c;
        }
        
        return b;
    }
};