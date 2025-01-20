class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>row(m),col(n);

        map<int,pair<int,int>>mp;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                mp[mat[i][j]]={i,j};
            }
        }
        int l=arr.size();
        for(int k=0;k<l;++k)
        {
            int val=arr[k];
            int i=mp[val].first;
            int j=mp[val].second;

            row[i]++;
            col[j]++;

            if(row[i]==n || col[j]==m) return k;
        }
        return (m*n);
    }
};