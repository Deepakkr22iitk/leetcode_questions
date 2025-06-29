class Solution {
public:
    const int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int res=0;
        int l=0,h=n-1;
        vector<int>pre={1};
        for(int i=1;i<=n;++i) pre.push_back((pre.back()<<1)%mod);   

        sort(begin(nums), end(nums));
        while(l<=h) 
        {
            if(nums[l]+nums[h]>target) h--; 
            else res=(res+pre[h-l++])%mod;
        }
        return res;
    }
};