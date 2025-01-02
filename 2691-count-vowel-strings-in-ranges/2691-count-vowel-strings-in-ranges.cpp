class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>rk(n);
        for(int i=0;i<n;++i)
        {
            string temp=words[i];
            int l=temp.size();
            if((temp[0]=='a' || temp[0]=='e' || temp[0]=='i' || temp[0]=='o' || temp[0]=='u')&&(temp[l-1]=='a' || temp[l-1]=='e' || temp[l-1]=='i' || temp[l-1]=='o' || temp[l-1]=='u'))
                rk[i]=1;
        }
        
        for(int i=1;i<n;++i)
        {
            rk[i]=rk[i]+rk[i-1];
        }
        
        int q=queries.size();
        vector<int>ans(q);
        for(int i=0;i<q;++i)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            
            if(l==0)
            {
                ans[i]=rk[r];
            }
            else ans[i]=(rk[r]-rk[l-1]);
        }
        return ans;
    }
};