class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>dp(m,vector<int>(n));
        for(int i=0;i<m;++i) 
        {
            dp[i][0]=mat[i][0];
            for(int j=1;j<n;++j)
            {
                if(mat[i][j]==1) dp[i][j]=1+dp[i][j-1];
            }
        }


        int result=0;
        for(int j=0;j<n;++j)  //from left to right
        {
            for(int i=0;i<m;++i)  //from top to bottom
            {
                int minimum=dp[i][j];
                for(int k=i;k>=0;--k)   //from i to top (count the number of rectangles that can be made)
                {
                    minimum=min(minimum,dp[k][j]); //the number of rectangles that can be made with the right edge extended from mat[i][j] to mat[k][j]
                    if(minimum==0) break;       // As It won't make any sense to going up from here.
                    result+=minimum;
                }
            }
        }
        return result;
    }
};