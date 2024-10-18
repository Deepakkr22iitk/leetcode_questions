class Solution {
public:
    // Each of the state can be identified uniquely by the OR value upto that point and the current arr index.
    // E.g., [3,1,2,4]  then subset1: [3,1] OR_value=3 and index=2  ,,,, subset2=[3] OR_value=3 and index=2

    // Although Recursive solution would work here as n<=16. then, TC==O(2^n)
    // The TC of this memoized approach --> O(n*mx_OR_val) because at each step only (index and OR_value) changes.
    int helper(vector<int>& nums,int i,int &n,vector<vector<int>>&dp,int val,int &mx_OR_val)
    {
        if(i==n)
        {
           return (val==mx_OR_val);
        }
        if(dp[i][val]!=-1) return dp[i][val];

        dp[i][val]=helper(nums,i+1,n,dp,(val|nums[i]),mx_OR_val)+helper(nums,i+1,n,dp,val,mx_OR_val);
        return dp[i][val];
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int mx_OR_val=0;
        for(auto &x:nums) mx_OR_val|=x;

        vector<vector<int>>dp(n,vector<int>(mx_OR_val+1,-1));

        return helper(nums,0,n,dp,0,mx_OR_val);
    }
};