class Solution {
public:
    // time/space: O(logn)/O(logn)
    int minimumOneBitOperations(int n) {
        unordered_map<int, int> dp = {{0, 0}, {1, 1}};
        return helper(n, dp);
    }
private:
    int helper(int n, unordered_map<int, int>& dp) {
        // memoization
        if (dp.count(n) != 0) return dp[n];

        // find the position of the leftmost bit
        int bit = getLeftmostBit(n);
        int k = bit - 1;

        // generate the magic number
        int magic110__0 = (1 << bit) | (1 << k);

        // convert `n` to `magic110__0`
        int step1 = helper(n ^ magic110__0, dp);
        // convert `magic110__0` to `2 ^ k`
        int step2 = 1;
        // convert `2 ^ k` to `0`
        int step3 = (1 << (k + 1)) - 1;

        // memoization
        return dp[n] = (step1 + step2 + step3);
    }
    int getLeftmostBit(int n) {
        int bit = 0;
        while (n > 1) { n >>= 1, bit++; }
        return bit;
    }
};