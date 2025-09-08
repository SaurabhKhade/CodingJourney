class Solution {
public:
    vector<int> sumZero(int n) {
        if (n == 1) return { 0 };
        vector<int> vec;
        for (int i=1; i<n; i++) {
            vec.emplace_back(-i);
        }

        vec.emplace_back(n * (n-1) / 2);
        return vec;
    }
};