class Solution {
public:
    int f_memo(vector<int> &nums,vector<int> &dp,int n,int idx)
    {
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int looted=0,not_looted=0;
        looted=nums[idx]+f_memo(nums,dp,n,idx+2);
        not_looted=0+f_memo(nums,dp,n,idx+1);

        return dp[idx]=max(looted,not_looted);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        vector<int> dp1(n,-1),dp2(n,-1);
        int s1=f_memo(nums,dp1,n-1,0);
        int s2=f_memo(nums,dp2,n,1);

        return max(s1,s2);
    }
};