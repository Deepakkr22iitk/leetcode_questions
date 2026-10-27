class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result(m);

        for (int i = 0; i < m; i++) {
            string ans = "";

            for (int j = 0; j < n; j++) {
                if (i == 0 || j == n - 1) {
                    ans += '.';
                } else {
                    ans += '#';
                }
            }

            result[i] = ans;
        }

        return result;
    }
};