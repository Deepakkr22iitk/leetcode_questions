class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalBottles = numBottles; // in starting

        while (numBottles >= numExchange) { // step-by-step
            numBottles -= numExchange; // at the cost of numExchange we 
            totalBottles += 1; // adding only one full water bottle
            numBottles += 1; // that water bottle will be empty 
            numExchange ++; // at each step rate is increasing
        }

        return totalBottles;
    }
};