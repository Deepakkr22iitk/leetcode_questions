class Solution {
public:
    const int mod=1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1);
        dp[0]=1;
        int ans=0;
        for(int i=1;i<=high;++i)
        {
            if(i>=zero) dp[i]=(dp[i]%mod + dp[i-zero] %mod)%mod;
            if(i>=one) dp[i]=(dp[i]%mod + dp[i-one] %mod)%mod;
            
            dp[i]=dp[i]%mod;
            if(i>=low) ans=(ans%mod + dp[i]%mod)%mod;
        }
        return ans;
    }
};