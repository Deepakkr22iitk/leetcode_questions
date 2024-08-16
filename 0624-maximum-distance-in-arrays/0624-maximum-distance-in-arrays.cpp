class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        sort(arrays.begin(),arrays.end());
        int l=arrays[0][0];
        int h=arrays[0].back();

        int ans=0;
        for(int i=1;i<n;++i)
        {
            ans=max(ans,(arrays[i].back()-l));
            ans=max(ans,(h-arrays[i][0]));
            l=min(l,arrays[i][0]);
            h=max(h,arrays[i].back());
        }
        return ans;
    }
};