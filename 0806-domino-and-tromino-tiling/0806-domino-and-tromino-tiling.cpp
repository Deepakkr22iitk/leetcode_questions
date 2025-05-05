class Solution {
public:
    const int mod=1000000007;
    // <-- Explanation by Zhengkai Wei-->
    // Here is my understanding of why dp[n]=dp[n-1]+dp[n-2]+ 2*(dp[n-3]+...+dp[0]):
    // For all f(n-1), it can be transformed to f(n) by appending a domino |, hence f(n-1) * 1.
    // For all f(n-2), though f(2) contains 2 cases: = and ||, however the case || has been covered by f(n-1) plus |,
    // so literally there is only one distinct way to transform f(n-2) to f(n), hence f(n-2)*1.
    // For all f(n-i) where i > 2, the ways complementing them to f(n) by dominoes (either horizontal or vertical domino) have been 
    // covered by f(n-1) and f(n-2),
    // hence the remaining distinct ways are either appending triminoes or combination of triminoes and dominoes. And there are always 
    // only 2 ways to do this (as demonstrated in the picture in this post), all of them can be considered as derived from either f(3) or f(4) by adding dominoes.

    // dp[n] = dp[n-1] + dp[n-2] + 2 * (dp[n-3] + ... + dp[0]) -- E1
    // dp[n-1] = dp[n-2] + dp[n-3] + 2 * (dp[n-4] + ... + dp[0]) -- E2

    // E1 - E2:
    // dp[n] - dp[n-1] = dp[n-1] + dp[n-3]
    // --> dp[n] = 2*dp[n-1] + dp[n-3]
    
    int solve(int n,vector<int>&dp){
        if(n<=0) return 0;
        else if(n==1) return dp[n]=1;
        else if(n==2) return dp[n]=2;
        else if(n==3) return dp[n]=5;

        if(dp[n]!=-1) return dp[n];
        
        long long ans = 2*1LL*solve(n-1,dp) + solve(n-3,dp); 
        return dp[n]=(int)(ans%mod);
    }

    int numTilings(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};