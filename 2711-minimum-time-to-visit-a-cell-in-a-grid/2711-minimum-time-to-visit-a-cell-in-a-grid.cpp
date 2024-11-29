class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        
        vector<vector<int>>vis(m,vector<int>(n));
        priority_queue<vector<int>, vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});     // {time, row, col}
        
        vector<int>dr={1,0,-1,0,1};

        while(!pq.empty())
        {
            auto curr=pq.top();
            pq.pop();
            int time=curr[0];
            int row=curr[1];
            int col=curr[2];
            
            if(row==m-1 && col==n-1) return time;
            
            if(vis[row][col]==true) continue;

            vis[row][col]=true;

            for(int k=0;k<4;++k)
            {
                int newrow=row+dr[k];
                int newcol=col+dr[k+1];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && vis[newrow][newcol]==0)
                {
                    if(grid[newrow][newcol]<=(time+1))
                    {
                        pq.push({time+1,newrow,newcol});
                    }
                    else     // so, now grid value is higher compared to time. so, we would have to move back and forth b/w  
                    {        // {row, col} and the cell previous to it. This extra is the wait time. 
                        int extra= ((grid[newrow][newcol]-time)%2)?0:1;
                        pq.push({grid[newrow][newcol]+extra,newrow,newcol});
                    }
                }
            }
        }
        return -1;
    }

    // Calculation of this extra variable:
    //Let's say time for target cell is 4 and current time is 2, difference = 2 (even).
    // Move to prev cell, time = 3
    // Move to curr cell, time = 4
    // Move to target cell, time = 5.
    // Hence we reach target cell with time: target cell time + 1 when difference between target cell time and curr cell time is even.

    // Let's say time for target cell is 5 and current time is 2, difference = 3 (odd).
    // Move to prev cell, time = 3
    // Move to curr cell, time = 4
    // Move to target cell, time = 5.
    //Hence we reach target cell with time: target cell time when difference between target cell time and curr cell time is odd.
};