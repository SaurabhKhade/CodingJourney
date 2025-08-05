class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!used[j] && fruits[j] <= baskets[i]) {
                    used[j] = true;
                    break;
                }
            }
        }

        int cnt = 0;
        for(bool status : used) {
            cnt += !status;
        }

        return cnt;
    }
};
