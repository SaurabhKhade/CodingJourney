class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int stepBack1 = cost[0], stepBack2 = cost[1];
        for (int i=2; i<cost.size(); i++) {
            int c = min(stepBack1, stepBack2) + cost[i];
            stepBack1 = stepBack2;
            stepBack2 = c;
        }

        return min(stepBack1, stepBack2);
    }
};