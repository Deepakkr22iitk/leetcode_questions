class Solution {
public:
    bool helper(int i, int &n,auto &nums,int target,int curr,auto &dp)
    {
        if(i==n) return (curr==target);

        if(curr>target) return false;

        if(curr==target) return true;

        if(dp[i][curr]!=-1) return dp[i][curr];

        bool flag=helper(i+1,n,nums,target,curr,dp);
        if(flag==true) return dp[i][curr]=true;
        flag|=helper(i+1,n,nums,target,curr+nums[i],dp);

        return dp[i][curr]=flag;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &x:nums) sum+=x;
        if(sum%2) return false;

        vector<vector<int>>dp(n+1,vector<int>(sum/2 + 1,-1));
        return helper(0,n,nums,sum/2,0,dp);
    }
};