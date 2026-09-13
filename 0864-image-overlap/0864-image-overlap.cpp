class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();

        vector<pair<int,int>> pos1,pos2;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(img1[i][j]==1) pos1.push_back({i,j});
                if(img2[i][j]==1) pos2.push_back({i,j});
            }
        }

        int ans=0;
        map<pair<int,int>,int> freq;
        for(auto it1:pos1)
        {
            for(auto it2:pos2)
            {
                int r=(it2.first-it1.first);
                int c=(it2.second-it1.second);

                freq[{r,c}]++;
                ans=max(ans,freq[{r,c}]);
            }
        }
        return ans;
    }
};