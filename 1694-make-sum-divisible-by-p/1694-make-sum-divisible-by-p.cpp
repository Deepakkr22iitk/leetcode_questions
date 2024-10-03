class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int total=0;

        for(auto &x:nums) total=(total+x)%p;

        int target=total%p;
        if(target==0) return 0;

        unordered_map<int,int>ind;
        ind[0]=-1;
        int ans=n;
        int curr=0;
        for(int i=0;i<n;++i)
        {
            curr=(curr+nums[i])%p;

            int req=(curr-target+p)%p;    // As the necessary condition is (curri -currj)%p==target. so, currj=.....
            if(ind.find(req)!=ind.end())
            {
                ans=min(ans,i-ind[req]);
            }
            ind[curr]=i;
        }
        if(ans==n) return -1;
        return ans;
    }
};