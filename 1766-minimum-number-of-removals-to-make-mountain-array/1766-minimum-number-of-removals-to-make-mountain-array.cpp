class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        vector<int>left_inc(n,1),right_inc(n,1);
        for(int i=1;i<n;++i)
        {
            int val=nums[i];
            for(int j=i-1;j>=0;--j)
            {
                if(nums[j]<val) left_inc[i]=max(left_inc[i],left_inc[j]+1);
            }
        }

        for(int i=n-2;i>=0;--i)
        {
            int val=nums[i];
            for(int j=i+1;j<n;++j)
            {
                if(nums[j]<val) right_inc[i]=max(right_inc[i],right_inc[j]+1);
            }
        }

        for(int i=1;i<n-1;++i)
        {
            int rem=n-i-1;

            if(left_inc[i]==1 || right_inc[i]==1) continue;

            int cost=(i-left_inc[i]+1) + (rem-right_inc[i]+1);
            ans=min(ans,cost);
        }
        return ans;
    }
};