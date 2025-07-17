class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>>dp(k,vector<int>(k));   // Here dp[i][j] --> length of max subsequence when curr_remainder=i
        for(int i=0;i<n;++i)       // ans last_remainder in the subsequence is 'j'. This is necessary when for curr num 
        {                          // remainder is '5' and chosen '3' as the last remainder. Then, we can only those values 
            int rem=(nums[i]%k);    // from '3' having '5' as the remainder.
            for(int last_rem=0;last_rem<k;++last_rem)
            {
                dp[rem][last_rem]=max(dp[rem][last_rem], 1+ dp[last_rem][rem]);
                ans=max(ans,dp[rem][last_rem]);
            }
        }
        return ans;
    }
};