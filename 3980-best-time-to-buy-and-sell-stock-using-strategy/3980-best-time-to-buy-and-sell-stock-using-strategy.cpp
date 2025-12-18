class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size(), h = k >> 1;
        long long base = 0, prev = 0, nxt = 0, best = 0;

        for (int i = 0; i < n; i++)
            base += 1LL * strategy[i] * prices[i];

        for (int i = 0; i < k; i++) {
            prev += 1LL * strategy[i] * prices[i];
            if (i >= h) nxt += prices[i];
        }

        best = max(0LL, nxt - prev);

        for (int r = k; r < n; r++) {
            int l = r - k + 1;
            prev += 1LL * strategy[r] * prices[r]
                  - 1LL * strategy[l - 1] * prices[l - 1];
            nxt += prices[r] - prices[l - 1 + h];
            best = max(best, nxt - prev);
        }

        return base + best;
    }
};