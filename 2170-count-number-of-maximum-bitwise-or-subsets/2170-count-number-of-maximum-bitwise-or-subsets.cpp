class Solution {
public:
    // Each of the state can be identified uniquely by the OR value upto that point and the current arr index.
    // E.g., [3,1,2,4]  then subset1: [3,1] OR_value=3 and index=2  ,,,, subset2=[3] OR_value=3 and index=2

    // Although Recursive solution would work here as n<=16. then, TC==O(2^n) [Take and Not_Take case]
    // The TC of this memoized approach --> O(n*mx_or_value) because at each step only (index and OR_value) changes.
    int helper(vector<int>& nums,int i,int &n,vector<vector<int>>&dp,int val,int &mx_or_value)
    {
        if(i==n)
        {
           return (val==mx_or_value);
        }
        if(dp[i][val]!=-1) return dp[i][val];

        dp[i][val]=helper(nums,i+1,n,dp,(val|nums[i]),mx_or_value)+helper(nums,i+1,n,dp,val,mx_or_value);
        return dp[i][val];
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int mx_or_value=0;       // (a || b)>=max(a,b)
        for(auto &x:nums) mx_or_value|=x;

        vector<vector<int>>dp(n,vector<int>(mx_or_value+1,-1));  // Here dp[i][j] represents the number of subset starting from index
        // 'i' having initial value of OR as 'j' whose subsets OR becomes equal of mx_or_value

        return helper(nums,0,n,dp,0,mx_or_value);
    }
};