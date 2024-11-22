class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int>mp;
        int ans=0;
        for(auto &x:matrix)
        {
            int len=x.size();
            string curr="";
            int first=x[0];
            for(int i=0;i<len;++i)
            {
                if(x[i]==first) curr+='1';
                else curr+='0';
            }
            mp[curr]++;
        }

        for(auto &y:mp) ans=max(ans,y.second);

        return ans;
    }
};