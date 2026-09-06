class Solution {
public:
    // int f_recurr(int i, int j, string &s, string &t){
    //     if(j < 0) return 1;
    //     if(i < 0) return 0;

    //     if(s[i] == t[j]) return f_recurr(i - 1, j, s, t) + f_recurr(i - 1, j - 1, s, t);

    //     else return f_recurr(i - 1, j, s, t);
    // }

    int f_memo(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1]) return dp[i][j]=(f_memo(i - 1, j, s, t, dp) + f_memo(i - 1, j - 1, s, t, dp));

        else return dp[i][j]=f_memo(i - 1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        // return f_recurr(n-1,m-1,s,t);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f_memo(n, m, s, t, dp);

        // // the next two solutions are not working [ERROR : signed integer overflow]

        // vector<vector<__int128>> dp(n+1,vector<__int128>(m+1,0));
        // for(int i=0;i<=n;i++) dp[i][0]=1;

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(s[i-1]==t[j-1]) dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]);

        //         else dp[i][j]=dp[i-1][j];
        //     }
        // }

        // return (int)dp[n][m];

        // vector<long long> prev(m + 1, 0), curr(m + 1, 0);
        // prev[0]=1; curr[0]=1;

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         if(s[i - 1] == t[j - 1]) curr[j] = prev[j] + prev[j - 1];

        //         else curr[j] = prev[j];
        //     }
        //     prev = curr;
        // }

        // return prev[m];

    }
};