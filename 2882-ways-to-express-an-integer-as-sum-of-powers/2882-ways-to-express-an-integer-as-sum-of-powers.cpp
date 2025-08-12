class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> dp;
    int solve(int n,int x,int now,auto &dp)
    {
        if(n==0) return 1;
        if(pow(now,x)>n) return 0;

        if(dp[n][now] != -1) return dp[n][now];
        return dp[n][now] = (solve(n-pow(now,x),x,now+1,dp)%mod + solve(n,x,now+1,dp)%mod)%mod;
    }
    int numberOfWays(int n, int x) {
        dp.assign(n+1,vector<int>(301,-1));
        return solve(n,x,1,dp);
    }
};