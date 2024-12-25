class Solution {
public:
    int mxInMidCol(vector<vector<int>>& mat, int col)
    {
        int m=mat.size();
        int ans=0,last=mat[0][col];
        for(int i=1;i<m;++i)
        {
            if(mat[i][col]>last)
            {
                last=mat[i][col];
                ans=i;
            }
        }
        return ans;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        // we can also do a binary search on rows, instead of columns, it will work too.
        // the key idea of searching across columns is eliminate going through every element.
        // and after that we will search for the max row in that col and then we will check its 
        // left and right because its obviously greater than top and bottom in that col
        // and according to that we will shift left or right.
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int row=mxInMidCol(mat,mid);
            int left=(mid-1)>=0?mat[row][mid-1]:-1;
            int right=(mid+1)<n?mat[row][mid+1]:-1;
            if(left<mat[row][mid] && right<mat[row][mid])
            {
                return {row,mid};
            }
            if(left>mat[row][mid]) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};