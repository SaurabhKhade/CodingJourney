class Solution {
    unordered_map<int, int> map;
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        if (map.find(n) != map.end()) return map[n];
        return map[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};