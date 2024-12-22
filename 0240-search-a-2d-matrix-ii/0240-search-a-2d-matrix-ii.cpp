class Solution {
public:
//       <--decrease----
//     ^ # # # # # # # ★ |
//     | # . . . . . . . |
//    se . . . . . . . . in
//    ea . . . . . . . . cr
//    cr .             . ea
//    de .             . se
//     | .             # |
//     | ★ # # # # # # # \/
//       ---increase-->

//       only ★ can be the starting points
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // TC->O(n+m) as these are the max number of steps can be taken
        int m=matrix.size();
        int n=matrix[0].size();
        int row=0,col=n-1;
        while(row<m && col>=0)
        {
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]<target) row++;
            else col--; 
        }
        return false;
    }
};