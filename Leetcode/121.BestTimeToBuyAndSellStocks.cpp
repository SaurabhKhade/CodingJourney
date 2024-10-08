class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], maxProfit = 0;
        for (auto &i:prices) {
            if (minPrice > i) minPrice = i;
            if (maxProfit < i - minPrice) maxProfit = i - minPrice;
        }

        return maxProfit;
    }
};