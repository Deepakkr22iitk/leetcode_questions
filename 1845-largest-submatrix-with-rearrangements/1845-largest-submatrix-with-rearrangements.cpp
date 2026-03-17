class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        // Code
        int n = matrix.size(); // Row Size
        int m = matrix[0].size(); // Col Size

        int ans = INT_MIN;
        for(int j = 0; j < m; j++) // Col
        {
            for(int i = 1; i < n; i++) // Row
            {
                if(matrix[i][j] == 1)
                    matrix[i][j] += matrix[i-1][j];
            }
        }

        for(int i = 0; i < n; i++) // Row
        {
            // Arrange the row in sorted and decreasing order
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
            for(int j = 0; j < m; j++) // Col
            {
               int length = matrix[i][j];
               int breadth = j + 1;
               ans = max( ans, length * breadth);
            }
        }
        return ans;
    }
};