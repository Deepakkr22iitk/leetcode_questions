class Solution {
public:
    int maxDifference(string s) {
        int len=s.size();
        vector<int>freq(26);
        int ans=-len;
        for(int i=0;i<len;++i) freq[s[i]-'a']++;

        for(int i=0;i<26;++i)
        {
            bool flag=(freq[i]%2==1);
            if(flag)
            {
                for(int j=0;j<26;++j)
                {
                    if(freq[j]>0)
                    {
                        if((freq[j]%2)!=flag)
                        {
                            int curr=freq[i]-freq[j];
                            ans=max(ans,curr);
                        }
                    }
                }
            }
        }
        return ans;
    }
};