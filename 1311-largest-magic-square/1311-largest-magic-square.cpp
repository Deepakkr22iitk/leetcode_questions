class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n < 2 || m < 2) return 1;

        vector<vector<long long>> row(n, vector<long long>(m + 1, 0));
        vector<vector<long long>> col(n + 1, vector<long long>(m, 0));
        vector<vector<long long>> d1(n + 1, vector<long long>(m + 2, 0));
        vector<vector<long long>> d2(n + 1, vector<long long>(m + 2, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j] = d2[i][j + 1] + grid[i][j];
            }
        }

        for (int k = min(n, m); k > 1; --k) {
            for (int r = 0; r <= n - k; ++r) {
                for (int c = 0; c <= m - k; ++c) {
                    long long target = row[r][c + k] - row[r][c];

                    if (d1[r + k][c + k] - d1[r][c] != target) continue;
                    if (d2[r + k][c] - d2[r][c + k] != target) continue;

                    bool match = true;
                    for (int i = 0; i < k; ++i) {
                        if (row[r + i][c + k] - row[r + i][c] != target) {
                            match = false;
                            break;
                        }
                    }
                    if (!match) continue;

                    for (int j = 0; j < k; ++j) {
                        if (col[r + k][c + j] - col[r][c + j] != target) {
                            match = false;
                            break;
                        }
                    }

                    if (match) return k;
                }
            }
        }
        return 1;
    }
};