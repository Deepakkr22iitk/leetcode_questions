class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        
        vector<long long>curr(n);
        for(int j=0;j<n;++j) curr[j]=points[0][j];

        for(int i=0;i<m-1;++i)
        {
            vector<long long>left_part(n),right_part(n);   //left_part[j]=Max till j'th index from left-to-right 
            vector<long long>next(n);                   // Building the next vector while being at curr row

            left_part[0]=curr[0];
            for(int j=1;j<n;++j) left_part[j]=max(left_part[j-1]-1, curr[j]);

            right_part[n-1]=curr[n-1];
            for(int j=n-2;j>=0;--j) right_part[j]=max(right_part[j+1]-1,curr[j]);

            for(int j=0;j<n;++j)              // Building the next row vector
            {
                next[j]=points[i+1][j]+max(left_part[j],right_part[j]);
            }

            curr=next;
        }

        long long ans=0;
        for(int j=0;j<n;++j) ans=max(ans,curr[j]);
        return ans;
    }
};