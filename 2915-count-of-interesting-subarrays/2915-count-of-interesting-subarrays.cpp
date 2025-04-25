class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        vector<int>val(n);
        for(int i=0;i<n;++i)
        {
            if((nums[i]%modulo)==k) val[i]=1;
            else val[i]=0;
        }

        long long ans=0;
        map<int,int>rk;
        modulo=1LL*modulo;
        rk[0]=1;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=1LL*val[i];
            long long mod_val=sum % modulo;
            long long rem=mod_val-1LL*k;
            if(rem<0) rem+=modulo;

            ans+=rk[rem];
            rk[mod_val]++;
        }
        return ans;
    }
};