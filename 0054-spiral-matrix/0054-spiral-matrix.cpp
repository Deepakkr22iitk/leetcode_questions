class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> ans;
        int sr=0,sc=0,er=n-1,ec=m-1;
        while(sr<=er && sc<=ec)
        {
            for(int j=sc;j<=ec;++j)
            {
                ans.push_back(matrix[sr][j]);
            }
            sr++;
            for(int i=sr;i<=er;++i)
            {
                ans.push_back(matrix[i][ec]);
            }
            ec--;
            // do little bit of handwork for getting the reason of sr<=er
            for(int j=ec;j>=sc && sr<=er;--j)
            {
                ans.push_back(matrix[er][j]);
            }
            er--;
            for(int i=er;i>=sr && sc<=ec;--i)
            {
                ans.push_back(matrix[i][sc]);
            }
            sc++;
        }
        return ans;
    }
};