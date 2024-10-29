class Solution {
public:
    int dr[3]={-1,0,1};
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>pre(m,vector<int>(n));
        
        // Since, here the moves are allowed only such that each time 'col+1' is being done. so, our traversal would be 
        // based on column.
        for(int j=n-2;j>=0;--j)
        {
            for(int i=0;i<m;++i)
            {
                int mx=0;
                for(int k=0;k<3;++k)
                {
                    int newi=i+dr[k];
                    if(newi>=0 && newi<m && grid[newi][j+1]>grid[i][j])
                    {
                        mx=max(pre[newi][j+1]+1,mx);
                    }
                }
                pre[i][j]=mx;
            }
        }
        
        int ans=0;
        for(int i=0;i<m;++i)
        {
            ans=max(ans,pre[i][0]);
        }
        return ans; 
    }
};