class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n=words.size();
        int ans=0;
        set<int>st;
        for(auto &x:allowed) st.insert(x);

        for(int i=0;i<n;++i)
        {
            string curr=words[i];
            int len=curr.size();
            int j;
            for(j=0;j<len;++j)
            {
                if(st.find(curr[j])==st.end()) break;
            }
            if(j==len) ans++;
        }
        return ans;
    }
};