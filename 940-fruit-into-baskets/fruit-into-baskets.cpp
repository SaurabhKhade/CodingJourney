class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int distFruits = 0;
        vector<int> vec(1e5);
        int i=0, j = 0, mx = 0;

        while (j < fruits.size()) {
            vec[fruits[j]]++;
            if (vec[fruits[j]] == 1) {
                distFruits++;
            }
            j++;

            while (distFruits > 2) {
                vec[fruits[i]]--;
                if (vec[fruits[i]] == 0) {
                    distFruits--;
                }
                i++;
            }

            mx = max(mx, j-i);
        }

        return mx;
    }
};