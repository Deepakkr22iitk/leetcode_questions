class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>suff(n);
        suff[n-1]=1LL*nums[n-1];
        for(int i=(n-2);i>=0;--i) suff[i]=suff[i+1]+1LL*nums[i];

        long long pre=0;
        int ans=0;
        for(int i=0;i<(n-1);++i)
        {
            pre+=1LL*nums[i];
            if(pre>=suff[i+1]) ans++;
        }
        return ans;
    }
};