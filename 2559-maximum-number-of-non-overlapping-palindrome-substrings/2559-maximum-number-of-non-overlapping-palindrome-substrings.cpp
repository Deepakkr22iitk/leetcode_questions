class Solution {
public:
    int n;
    vector<vector<bool>> bld;
    vector<int> dp;

    int rec(int i, string &s, int k) {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Skip the current character
        int count = rec(i + 1, s, k);

        // Try every palindrome starting at i
        for (int j = i; j < n; j++) {
            if (bld[i][j] && (j - i + 1 >= k)) {
                count = max(count, 1 + rec(j + 1, s, k));
            }
        }

        return dp[i] = count;
    }

    int maxPalindromes(string s, int k) {
        n = s.size();

        // Build palindrome table
        bld.resize(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || bld[i + 1][j - 1])) {
                    bld[i][j] = true;
                }
            }
        }

        dp.resize(n, -1);

        return rec(0, s, k);
    }
};