class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));

        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1]; 
            }
        }

        int ans=0;
        int mx=min(m,n);
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(matrix[i-1][j-1]==1)
                {
                    ans++;
                    for(int k=2;k<=mx;++k)       // Check for each of the size of the square
                    {
                        if((i+k-1)>m  || (j+k-1)>n) break;

                        int val=dp[i+k-1][j+k-1];
                        val-=dp[i-1][j+k-1];
                        val-=dp[i+k-1][j-1];
                        val+=dp[i-1][j-1];

                        if(val==(k*k)) ans++;
                    }
                }
            }
        }
        return ans;
    }
};