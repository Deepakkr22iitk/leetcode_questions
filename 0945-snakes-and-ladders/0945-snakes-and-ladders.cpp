class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> mindist(n*n+1,-1);
        queue<int>q;
        mindist[1]=0;
        q.push(1);
        while(!q.empty()) 
        {
            int curr=q.front();
            q.pop();
            for (int i=curr+1;i<=min(curr+6, n*n);++i) 
            {
                int row=(n-1-(i-1)/n);
                int col=(i-1)%n;
                if(n%2==0 && row%2==0) col=(n-1-col);
                if(n%2==1 && row%2==1) col=(n-1-col);

                int destination=board[row][col]!=-1?board[row][col]:i;
                if (mindist[destination]==-1) 
                {
                    mindist[destination]=mindist[curr]+1;
                    q.push(destination);
                }
            }
        }
        return mindist[n*n];
    }
};