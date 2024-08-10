class Solution {
public:
    vector<int>dr={1,0,-1,0,1};
    void floodfill(vector<vector<int>>&grid,int i,int j,int len)
    {
        grid[i][j]=1;
        for(int k=0;k<4;++k)
        {
            int ni=i+dr[k];
            int nj=j+dr[k+1];

            if(ni>=0 && ni<len && nj>=0 && nj<len && grid[ni][nj]==0) floodfill(grid,ni,nj,len);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int len=grid.size();
        vector<vector<int>>expanded_grid(len*3,vector<int>(len*3));

        for(int i=0;i<len;++i)
        {
            for(int j=0;j<len;++j)
            {
                int r=i*3;
                int c=j*3;

                if(grid[i][j]=='\\')
                {
                    expanded_grid[r][c]=1;
                    expanded_grid[r+1][c+1]=1;
                    expanded_grid[r+2][c+2]=1;
                }
                else if(grid[i][j]=='/')
                {
                    expanded_grid[r][c+2]=1;
                    expanded_grid[r+1][c+1]=1;
                    expanded_grid[r+2][c]=1;
                }
            }
        }

        int ans=0;
        for(int i=0;i<(len*3);++i)
        {
            for(int j=0;j<(len*3);++j)
            {
                if(expanded_grid[i][j]==0)
                {
                    floodfill(expanded_grid,i,j,len*3);
                    ans++;
                }
            }
        }
        return ans;
    }
};