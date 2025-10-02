class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalBottles = numBottles;

        while (numBottles >= numExchange) {
            totalBottles += 1;
            numBottles -= numExchange;
            numBottles += 1;
            numExchange ++;
        }

        return totalBottles;
    }
};