class Solution {
public:
    int solve(int i, int j, vector<int>& piles, vector<vector<int>>& dp, vector<int>& pref) {
        if (i > j) return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int total = pref[j + 1] - pref[i];

        int left = solve(i + 1, j, piles, dp, pref);
        int right = solve(i, j - 1, piles, dp, pref);

        return dp[i][j] = total - min(left, right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + piles[i];

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int total = pref[n];

        int first = solve(0, n - 1, piles, dp, pref);

        return first >= total - first;
    }
};