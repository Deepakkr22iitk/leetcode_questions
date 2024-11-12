class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int q=queries.size();
        vector<int>ans(q);
        sort(items.begin(),items.end());    // Sorted based on price
        int n=items.size();
        int mx=items[0][1];            // To keep track of the maximum beauty till each of the index 
        for(int i=1;i<n;++i)
        {
            if(items[i][1]>mx) mx=items[i][1];

            items[i][1]=mx;
        }
        // Now, beauty of each of the index are in sorted fashion
        for(int i=0;i<q;++i)
        {
            int val=queries[i];
            int ind=-1;
            int l=0,h=n-1;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(items[mid][0]<=val)
                {
                    ind=mid;
                    l=mid+1;
                }
                else h=mid-1;
            }
            if(ind==-1) ans[i]=0;
            else ans[i]=items[ind][1];
        }
        return ans;
    }
};