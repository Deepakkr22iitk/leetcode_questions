class Solution {
public:
    int mod=1e9+7;
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int word_len=words[0].size();
        int tar_len=target.size();
        if (word_len<tar_len) return 0; //Since we are always bound to the rule that in any of the i'th word I can take a character under consideration only 
        //if it's index value is greater than the previous one used. 

        vector<vector<int>>cnt(word_len,vector<int>(26)); // count of frequency of every character at i'th index
        for (int i=0;i<word_len;++i) 
        {
            for (int j=0;j<n;++j) 
            {
                cnt[i][words[j][i]-'a']++;
            }
        }

        vector<int>dp(tar_len+1);  // cnt of the number of ways to make string till first 'i'th index of target.
        for(int i=0;i<word_len;++i) 
        {
            //cout<<dp[0]<<" ";
            int prev=1; // Instead of using two 'dp' vector one to keep track of the last value and one to build the current one, we are smartly using 
            //prev and cur as before updating the (j+1)'th value we are storing it's last value in 'cur' and at the end 'prev' is assigned this value so, that It can be used in next iteration.
            for(int j=0;j<=i && j<tar_len;++j)   // Here j<=i because at max we can have (i+1) elements under consideration
            {
                int cur=dp[j+1];
                dp[j+1]=((1LL*cnt[i][target[j]-'a']%mod * 1LL*prev%mod)%mod + dp[j+1])%mod; //If earlier count of "ab"=3 and in this iteration freq of 'a'=2 so, count of "aba"=3*2=6
                prev=cur;
                //cout<<dp[j+1]<<" ";
            }
            //cout<<"\n";
        }
        return dp[tar_len];
        // Can see Aryan one too.
    }
};