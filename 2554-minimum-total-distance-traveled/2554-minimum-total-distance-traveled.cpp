class Solution {
public:
    long long helper(int i,int j,int n,int m,vector<int>&robot, vector<vector<int>>&factory,auto &dp)
    {
        if(i==n) return 0;
        if(j==m) return 1e17;

        if(dp[i][j]!=-1) return dp[i][j];

        int limit=factory[j][1];
        long long ans=1e17;
        long long prev=0;                   // To keep track of the distance travelled for this particular factory limit
        for(int k=0;k<limit && (i+k)<n;++k)                   // Pick 
        {
            prev+=abs(factory[j][0]-robot[i+k]);
            ans=min(ans,prev+helper(i+k+1,j+1,n,m,robot,factory,dp));
        }
        ans=min(ans,helper(i,j+1,n,m,robot,factory,dp));      // Not pick

        return dp[i][j]=ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        int n=robot.size();
        int m=factory.size();

        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1)); // dp[i][j]--> minm cost to process till i'th robot and j'th factory
        long long ans=helper(0,0,n,m,robot,factory,dp);
        return ans;
    }
};