class Solution {
    // nicely calculated the row and column with just one variable mid.
    // row=mid/n
    // col=mid%n.
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     int low=1;
    //     int high=m*n;
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         if(matrix[mid/m][mid-(m*(mid/m))]>target) high=mid-1;
    //         if(matrix[mid/m][mid-(m*(mid/m))]==target) return true;
    //         else low=mid+1;
    //     }
    //     return false;
    // }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        int start=0;
        int end=m*n-1;
        while(start<=end){
            int mid=(start+end)>>1;
            int row = mid / n;
            int col = mid % n;
            if(mat[row][col]==target){
                return true;
            }else if(mat[row][col]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return false;
    }
};