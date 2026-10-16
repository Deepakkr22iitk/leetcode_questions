class Solution {
    typedef long long ll;
    vector<ll> sum, sq, lazy;

    void apply(int node, int len, ll v) {
        sq[node] += 2 * v * sum[node] + v * v * len;
        sum[node] += v * len;
        lazy[node] += v;
    }

    void push(int node, int l, int r) {
        if (lazy[node]) {
            int mid = (l + r) / 2;
            apply(node * 2, mid - l + 1, lazy[node]);
            apply(node * 2 + 1, r - mid, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, 1);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);
        sum[node] = sum[node * 2] + sum[node * 2 + 1];
        sq[node] = sq[node * 2] + sq[node * 2 + 1];
    }

public:
    int sumCounts(vector<int>& nums) {
        const ll MOD = 1e9 + 7;
        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        ll ans = 0;

        for (int j = 0; j < n; j++) {
            update(1, 0, n - 1, last[nums[j]] + 1, j);
            last[nums[j]] = j;
            ans = (ans + sq[1]) % MOD;
        }

        return (int) ans;
    }
};