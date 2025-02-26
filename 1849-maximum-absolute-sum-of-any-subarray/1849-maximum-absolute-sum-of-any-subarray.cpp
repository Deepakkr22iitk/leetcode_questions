class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>mx_ending_here(n),mn_ending_here(n);
        mx_ending_here[0]=max(0,nums[0]);
        for(int i=1;i<n;++i) mx_ending_here[i]=max(mx_ending_here[i-1]+nums[i],nums[i]);

        mn_ending_here[0]=nums[0];
        for(int i=1;i<n;++i) mn_ending_here[i]=min(mn_ending_here[i-1]+nums[i],nums[i]);

        int ans=0;
        for(int i=0;i<n;++i)
        {
            ans=max(ans,abs(mx_ending_here[i]));
            ans=max(ans,abs(mn_ending_here[i]));
        }
        return ans;
    }
};