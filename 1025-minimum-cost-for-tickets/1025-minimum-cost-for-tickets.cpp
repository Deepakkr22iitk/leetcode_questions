class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366);
        unordered_set<int>st(days.begin(),days.end());

        for(int i=1;i<=365;++i)
        {
            dp[i]=dp[i-1];
            if(st.find(i)!=st.end())
            {
                dp[i]=min((dp[i-1]+costs[0]),min((dp[max(0,i-7)]+costs[1]),(dp[max(0,i-30)]+costs[2])));
            }
        }
        return dp[365];
    }
};