class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        helper(1, n, result);
        return result;
    }
    void helper(int n, int limit, vector<int> &result) {
        for (int i=0; i<=(n==1?8:9) && n+i<=limit; i++) {
            result.push_back(n+i);
            if((n+i)*10 <= limit) helper((n+i)*10, limit, result);
        }
    }
};