class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>rk(26);
        int mx=0;
        for(auto &x: word)
        {
            rk[x-'a']++;
            mx=max(mx,rk[x-'a']);
        }
        int ans=INT_MAX;
        for(int i=1;i<=mx;++i)
        {
            int curr=0;
            for(int j=0;j<26;++j)
            {
                if(rk[j]<i) curr+=rk[j];      // Anything less than 'i'. I'm simply deleting them all
                
                else if(rk[j]>(i+k))
                {
                    int rem=rk[j]-i-k;       // Else I'll add the difference only from 'i+k'
                    curr+=rem;
                }
            }
            ans=min(ans,curr);
        }
        return ans;
    }
};