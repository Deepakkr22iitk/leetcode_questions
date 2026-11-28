class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n + 1, 0), mult(n + 1, 0);
        for (auto& it : items) cnt[it[0]]++;
        for (int f = 1; f <= n; f++)
            for (int k = f; k <= n; k += f) mult[f] += cnt[k];

        vector<long long> keys(n);
        long long minPrice = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long price = items[i][1];
            minPrice = min(minPrice, price);
            keys[i] = (price << 17) | (mult[items[i][0]] - 1);
        }
        sort(keys.begin(), keys.end());

        long long rem = budget, taken = 0;
        long long mask = (1LL << 17) - 1;
        for (long long key : keys) {
            long long price = key >> 17, gifts = key & mask;
            if (price >= 2 * minPrice) break;
            long long t = min(gifts, rem / price);
            taken += t;
            rem -= t * price;
            if (t < gifts) break;
        }
        return (int)(2 * taken + rem / minPrice);
    }
};