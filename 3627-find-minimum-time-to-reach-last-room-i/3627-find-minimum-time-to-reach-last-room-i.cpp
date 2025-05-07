class Solution {
public:
    // The idea is simple that since At any time It's possible to get the new minimum value for any particular grid and we are allowed
    // to move in any of the four directions. so, It's a graph based problem for BFS and not only DP
    // Similar to LC: 2290
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();

        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        ans[0][0]=0;

        queue<vector<int>>q;
        q.push({0,0,0});
        vector<int>dr={-1,0,1,0,-1};

        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();

            int row=temp[0];
            int col=temp[1];

            if(temp[2]>ans[row][col]) continue;   // We already got a lower value for this particular grid so, can ignore this 

            for(int k=0;k<4;++k) 
            {
                int nrow=row+dr[k];
                int ncol=col+dr[k+1];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && max(temp[2]+1,moveTime[nrow][ncol]+1)<ans[nrow][ncol])
                {
                    ans[nrow][ncol]=max(temp[2],moveTime[nrow][ncol])+1;
                    q.push({nrow,ncol,ans[nrow][ncol]});
                }
            }
        }
        return ans[n-1][m-1];
    }
};