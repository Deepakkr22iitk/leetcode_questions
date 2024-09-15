class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        map<int,int>mp;
        int ans=0;
        vector<int>parity(26);
        for(int i=0;i<n;++i)
        {
            int curr=s[i]-'a';
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                parity[curr]=1-parity[curr];
            }

            int val=0;
            for(int j=0;j<26;++j)
            {
                if(parity[j]==1) val=val|(1<<j);
            }
            if(val==0) ans=max(ans,i+1);

            if(mp.find(val)!=mp.end())
            {
                ans=max(ans,i-mp[val]);
            }
            else mp[val]=i;
        }
        return ans;
    }
};