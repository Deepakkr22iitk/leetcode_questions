class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        int mn=nums[0];
        for(int i=1;i<n;++i)
        {
            if(mn<nums[i])
            {
                int curr=nums[i]-mn;
                ans=max(ans,curr);
            }
            mn=min(mn,nums[i]);
        }
        return ans;
    }
};