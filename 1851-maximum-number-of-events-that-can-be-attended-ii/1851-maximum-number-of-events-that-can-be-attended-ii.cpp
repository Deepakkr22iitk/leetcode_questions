class Solution {
public:
    // The idea is to try out all the possibilities for each of 'k' and 'ind'
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
    int nextval(vector<vector<int>>& events,int target)
    {
        int n=events.size();
        int l=0,h=n-1;
        int ans=1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(events[mid][0]<=target)
            {
                ans=mid+1;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
    int helper(vector<vector<int>>& events,int ind,int k,vector<vector<int>>&dp)
    {
        int n=events.size();
        if(ind==n || k==0) return 0;

        if(dp[k][ind]!=-1) return dp[k][ind];

        int nextind=nextval(events,events[ind][1]);

        dp[k][ind]=max(helper(events,ind+1,k,dp),events[ind][2]+helper(events,nextind,k-1,dp));
        return dp[k][ind];
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end(),cmp);

        vector<vector<int>>dp(k+1,vector<int>(n,-1));
        return helper(events,0,k,dp);
    }
};