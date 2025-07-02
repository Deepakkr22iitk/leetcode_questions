class Solution {
public:
    const int mod=1e9+7;
    int possibleStringCount(string word, int k) {
        int len=word.size();
        vector<int>groups;
        int cnt=1;
        for(int i=1;i<len;++i)
        {
            if(word[i]==word[i-1]) cnt++;

            else
            {
                groups.push_back(cnt);
                cnt=1;
            }
        }
        groups.push_back(cnt);

        long long total=1;
        for(auto &x:groups) total=(total%mod * 1LL*x%mod)%mod;

        if(k<=groups.size()) return total;    // Since we need to take atleast '1' characters from each group.
        vector<int>dp(k); // dp[i] represents the number of ways to achieve a sum 'i' of chosen counts
        dp[0]=1;
        for(auto &x:groups)
        {
            vector<int>new_dp(k);
            long long sum=0;
            for(int s=1;s<k;++s)
            {
                sum=(sum%mod + dp[s-1]%mod)%mod;
                if(s>x) sum=(sum-dp[s-x-1]+mod)%mod;

                new_dp[s]=sum;
            }
            dp=new_dp;
        }

        long long invalid=0;
        for(int s=groups.size();s<k;++s) invalid=(invalid%mod + dp[s]%mod)%mod;    // 

        return (total%mod -invalid%mod+mod)%mod;
    }
};