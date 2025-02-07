class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int m=queries.size();
        int curr=0;
        vector<int>rk(m);
        map<int,int>cl;
        map<int,int>freq;
        for(int i=0;i<m;++i)
        {
            int ind=queries[i][0];
            int co=queries[i][1];
            int prev=-1;
            if(cl.find(ind)!=cl.end())
            {
                prev=cl[ind];
                int t=freq[prev];
                freq[prev]--;
                if(t==1) curr--;
            }
            freq[co]++;
            cl[ind]=co;
            if(freq[co]==1) curr++;
            
            rk[i]=curr;
        }
        return rk;
    }
};