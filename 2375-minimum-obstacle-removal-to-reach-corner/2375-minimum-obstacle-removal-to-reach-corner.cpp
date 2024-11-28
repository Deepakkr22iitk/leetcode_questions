class Solution {
public:
    // Here dp would not work :
    // Reason--> once I store the result of (i,j) using path let's say "path" then whenever I again come to (i,j), 
    // I just used the already saved result. So here is what my code assumes once we get the result for (i,j) 
    // then it's the optimal. But there is the possibility that a path from a different path that contributed to 
    // saving the dp result will be coming with less cost(i.e. cost == the number of blockers that needs to remove). 
    
    // So, BFS would be a good approach to check from each of the cell with an optimization of whether this particular cells
    // already has minimum value. Then, No point to call new BFS from this cell.
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));   // Minm obstacles removed to get to a particular cell

        queue<vector<int>>q;
        q.push({0,0,0});       // [row,col, minm_obstacles_removed_to_get_to_this_cell]
        int ans=(m*n);

        vector<int>dr={1,0,-1,0,1};

        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;++i)
            {
                auto temp=q.front();
                q.pop();
                int r=temp[0];
                int c=temp[1];
                
                if(r==m-1 && c==n-1)
                {
                    ans=min(ans,temp[2]);
                    continue;
                }

                if(temp[2]>dp[r][c])
                {
                    continue; // This is invalid path because we have already achieved better.
                }

                for(int k=0;k<4;++k)
                {
                    int newr=r+dr[k];
                    int newc=c+dr[k+1];

                    if(newr>=0 && newr<m && newc>=0 && newc<n && dp[newr][newc]>(temp[2]+grid[newr][newc]))
                    {
                        dp[newr][newc]=temp[2]+grid[newr][newc];

                        q.push({newr,newc,dp[newr][newc]});
                    }
                }
            }
        }
        return ans;
    }
};