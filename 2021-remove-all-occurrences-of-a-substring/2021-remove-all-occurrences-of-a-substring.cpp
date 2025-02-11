class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans=s;
        int len=s.size();
        int m=part.size();

        int i,j;
        for(i=0,j=0;i<len;++i)
        {
            ans[j++]=s[i];
            if(j>=m && ans.substr(j-m,m)==part) j-=m;      // If found a part then simply overwrite it.
        }

        return ans.substr(0,j);
    }
};