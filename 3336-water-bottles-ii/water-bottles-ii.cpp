class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = numBottles, empty = numBottles;
        while (empty >= numExchange) {
            drunk++;
            empty -= (numExchange - 1);
            numExchange++;
        }

        return drunk;
    }
};

// drunk = 15
// empty = 2
// nE = 8