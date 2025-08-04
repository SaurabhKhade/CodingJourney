class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int distFruits = 0;
        unordered_map<int, int> map;
        int i=0, j = 0, mx = 0;

        while (j < fruits.size()) {
            map[fruits[j]]++;
            if (map[fruits[j]] == 1) {
                distFruits++;
            }
            j++;

            while (distFruits > 2) {
                map[fruits[i]]--;
                if (map[fruits[i]] == 0) {
                    distFruits--;
                }
                i++;
            }

            mx = max(mx, j-i);
        }

        return mx;
    }
};