class Solution {
public:
    // As per the constraints, we can generate all of the Happy Strings of Length n and then return k'th index string.
    void helper(string &curr,int i,int &n,int &cnt,int &k,string &ans)
    {
        if(i==n)
        {
            cnt++;
            if(cnt==k) ans=curr;
            return;
        }
        
        for(int j=0;j<3;++j)
        {
            char c=(char)('a'+j);
            if(i>0 && curr[i-1]==c) continue;

            curr.push_back(c);
            helper(curr,i+1,n,cnt,k,ans);
            if(cnt==k) return;
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr="";
        int cnt=0;
        string ans="";
        helper(curr,0,n,cnt,k,ans);

        return ans;
    }
};