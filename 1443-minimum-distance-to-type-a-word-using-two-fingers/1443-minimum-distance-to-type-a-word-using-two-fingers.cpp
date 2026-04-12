class Solution {
public:
    int dp[301][27][27];

    int dist(int a, int b){
        if(a == 26 || b == 26) return 0;

        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;

        return abs(r1-r2) + abs(c1-c2);
    }

    int solve(int i, int f1, int f2, string &word){
        if(i == word.size()) return 0;

        if(dp[i][f1][f2] != -1)
            return dp[i][f1][f2];

        int cur = word[i] - 'A';

        int move1 = dist(f1, cur) +
                    solve(i+1, cur, f2, word);

        int move2 = dist(f2, cur) +
                    solve(i+1, f1, cur, word);

        return dp[i][f1][f2] = min(move1, move2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 26, word);
    }
};