class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>val;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                val.push_back(grid[i][j]);
            }
        }
        sort(val.begin(),val.end());
        int median=val[(m*n)/2];

        int ans=0;
        for(int i=0;i<m*n;++i)
        {
            if(abs(median-val[i]) %x !=0) return -1;

            ans+=abs(median-val[i])/x;
        }
        return ans;
    }
};