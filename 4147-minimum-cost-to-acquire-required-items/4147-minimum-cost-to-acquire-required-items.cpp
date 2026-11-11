class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        // Case 1: Buy both items separately
        long long c1 = 1LL * need1 * cost1
                     + 1LL * need2 * cost2;

        // Case 2: Buy only combined items
        long long c2 = 1LL * max(need1, need2) * costBoth;

        // Case 3: Buy combined items for overlapping needs,
        // then purchase the remaining requirement separately
        long long mult = need1 > need2 ? cost1 : cost2;

        long long c3 = 1LL * min(need1, need2) * costBoth
                     + 1LL * abs(need1 - need2) * mult;

        return min({c1, c2, c3});
    }
};