class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(isWater[i][j]==1)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<int>dr={-1,0,1,0,-1};
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();

            int r=temp.first;
            int c=temp.second;

            for(int k=0;k<4;++k)
            {
                int nr=r+dr[k];
                int nc=c+dr[k+1];

                if(nr>=0 && nr<m && nc>=0 && nc<n && ans[nr][nc]==-1) 
                {
                    ans[nr][nc]=1+ans[r][c];
                    q.push({nr,nc});
                }
            }
        }
        return ans;
    }
};