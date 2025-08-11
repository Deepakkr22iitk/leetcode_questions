class Solution {
public:
    int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        int now=1;
        while(n)
        {
            if(n%2)power.push_back(now*(n%2));
            n/=2;
            now*=2;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();++i)
        {
            long long answer=1;
            for(int j=queries[i][0];j<=queries[i][1];++j)
            {
                answer*=(1ll*power[j]);
                answer%=mod;
            }
            ans.push_back((int)(answer%mod));
        }
        return ans;
    }
};