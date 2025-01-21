class Solution {
public:
    // The idea is that as per the nature of movements allowed once a robot goes down it can't move up. so, try out each of the indices
    // where the first Robot would move down.
    long long gridGame(vector<vector<int>>& grid) {
        int m=grid[0].size();
        
        long long total_first=0;
        for(int j=0;j<m;++j) total_first+=1LL*grid[0][j];

        long long ans=1e15;
        long long curr_first=0,curr_second=0;
        for(int j=0;j<m;++j)
        {
            curr_first+=1LL*grid[0][j];

            long long rem_first=(total_first-curr_first);
            ans=min(ans,max(rem_first,curr_second));
        
            curr_second+=1LL*grid[1][j];
        }
        return ans;
    }
};