class Solution {
public:
    bool helper(string &a,string &b)
    {
        int len1=a.size();
        int len2=b.size();
        if(len2<len1) return false;

        string str=b.substr(0,len1);
        if(str!=a) return false;

        str=b.substr(len2-len1,len1);
        return (str==a);
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n-1;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(helper(words[i],words[j])) ans++;
            }
        }
        return ans;
    }
};