class Solution {
public:
    vector<int> l_len(vector<int>&groups,int n,vector<int>&parent)
    {
        vector<int>dp(n);
        dp[0]=1;
        parent[0]=-1;
        int ans=1;
        for(int i=1;i<n;++i)
        {
            if(groups[i]==1)
            {
                int j=i-1;
                while(j>=0)
                {
                    if(groups[j]==0)
                    {
                        parent[i]=j;
                        dp[i]=1+dp[j];
                        break;
                    }
                    j--;
                }
                if(j<0)
                {
                    dp[i]=1;
                    parent[i]=-1;
                }
            }
            else
            {
                int j=i-1;
                while(j>=0)
                {
                    if(groups[j]==1)
                    {
                        parent[i]=j;
                        dp[i]=1+dp[j];
                        break;
                    }
                    j--;
                }
                if(j<0)
                {
                    dp[i]=1;
                    parent[i]=-1;
                }
            }
        }
        return dp;
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>parent(n);
        vector<int>dp=l_len(groups,n,parent);
        
        int mx=1;
        int ind=0;
        for(int i=1;i<n;++i)
        {
            if(dp[i]>mx)
            {
                mx=dp[i];
                ind=i;
            }
        }
        
        vector<string>ans;
        ans.push_back(words[ind]);
        while(parent[ind]!=-1)
        {
            ans.push_back(words[parent[ind]]);
            ind=parent[ind];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};