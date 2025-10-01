public class Solution {
    public int NumWaterBottles(int numBottles, int numExchange) {
        int drink = 0, empty = 0;
        while (numBottles > 0) {
            drink += numBottles;
            numBottles += empty;
            empty = numBottles % numExchange;
            numBottles /= numExchange;
        }

        return drink;
    }
}