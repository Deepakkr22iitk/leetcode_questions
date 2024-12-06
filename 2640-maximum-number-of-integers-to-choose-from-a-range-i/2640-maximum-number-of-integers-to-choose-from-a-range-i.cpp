class Solution {
public:
    // The idea is simply choose smaller ones till the combined sum<=maxSum 
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(int i=0;i<banned.size();++i)
        {
            st.insert(banned[i]);
        }
        int cnt=0;
        long long sm=0;
        for(long long i=1;i<=n;++i)
        {
            if(st.find(i)==st.end())
            {
                if((sm+i)<=1LL*maxSum)
                {
                   cnt++;
                   sm+=i;   
                }
                else return cnt;
            }
        }
        return cnt;
    }
};