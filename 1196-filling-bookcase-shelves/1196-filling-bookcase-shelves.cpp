class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int>dp(n+1);
        dp[0]=0;

        for(int i=0;i<n;++i)
        {
            dp[i+1]=dp[i]+books[i][1];
            int width=0,h=0;
            for(int j=i;j>=0;--j)
            {
                width+=books[j][0];
                if(width<=shelfWidth)
                {
                    h=max(h,books[j][1]);
                    dp[i+1]=min(dp[j]+h,dp[i+1]);
                }
                else break;
            }
        }
        return dp[n];
    }
};