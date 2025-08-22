class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int mnX=INT_MAX,mnY=INT_MAX;
        int mxX=INT_MIN,mxY=INT_MIN;

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                {
                    mnX=min(mnX,i);
                    mxX=max(mxX,i);
                    mnY=min(mnY,j);
                    mxY=max(mxY,j);
                }
            }
        }
        return (mxX-mnX+1)*(mxY-mnY+1);
    }
};