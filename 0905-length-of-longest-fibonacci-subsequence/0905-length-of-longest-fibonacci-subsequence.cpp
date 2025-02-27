class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int res=0;
        vector<vector<int>>dp(n,vector<int>(n));  // dp[third][second]--> represents the max ending at the third index and previous index as second
        
        for(int third=2;third<n;++third)
        {
            int first=0, second=third-1;

            while(first<second)
            {
                if((arr[first]+arr[second])==arr[third])
                {
                    dp[third][second]=dp[second][first]+1;
                    res=max(res,dp[third][second]);

                    first++;
                    second--;
                }
                else if((arr[first]+arr[second])>arr[third]) second--;

                else first++;
            }
        }

        if(res==0) return 0;
        return (res+2);          // Add first two numbers too.
    }
};