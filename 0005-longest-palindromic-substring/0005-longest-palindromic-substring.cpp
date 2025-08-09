class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp)); //Initializing dp with -1
        int maxLen=1,start=0;
        for(int i=0;i<n;++i)
        {
            dp[i][i]=1;
            if(i+1<n && s[i]==s[i+1])  // handling palindrome of size 2
            {
                maxLen=2;
                start=i;
                dp[i][i+1]=1;
            } 
        }

        for(int len=3;len<=n;++len) // considering length 'len' of palindrome starting at index 'i'
        {
            for(int i=0;i<n-len+1;++i)
            {
                int j=i+len-1; 
                if(dp[i+1][j-1]==1 && s[i]==s[j])
                {
                    dp[i][j]=1;
                    start=i;
                    maxLen=len;
                }

            }
        }

        return s.substr(start,maxLen);




        // this will give wrong ans at some point, although this seems correct, but
        // it will give wrong ans for this particular test case : "aacabdkacaa"

        // string text2=text1;
        // reverse(text2.begin(),text2.end());
        // int n=text1.size();
        // int m=n;
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // int ans=0;
        // int ind=0;
        // for(int ind1 = 1; ind1 <= n; ind1++){
        //     for(int ind2 = 1; ind2 <= m; ind2++){
        //         if(text1[ind1 - 1] == text2[ind2 -1]) dp[ind1][ind2] =  1 + dp[ind1 - 1][ind2 - 1];

        //         else dp[ind1][ind2] = 0;
        //         if(dp[ind1][ind2]>ans)
        //         {
        //             ans=max(ans,dp[ind1][ind2]);
        //             ind=ind1;
        //         }
        //     }
        // }
        // cout<<ind<<" "<<ans<<" ";
        // return text1.substr(ind-ans,ans);
    }
};