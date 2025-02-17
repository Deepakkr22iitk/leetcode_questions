class Solution {
public:
    // The idea is to generate subsequences of all the lengths and then calculate the answer. Keep in Mind of duplicate occurences too.
    vector<int>fact={1,1,2,6,24,120,720,5040};
    int ans=0;
    void helper(string &tiles,int ind,int &n, set<string>&st,string curr)
    {
        if(ind==n)
        {
            if(curr.size()==0) return;
            sort(curr.begin(),curr.end());
            if(st.find(curr)==st.end())
            {
                st.insert(curr);
                int divide=1;          // To keep track of the equal cnt factorial
                int len=curr.size();
                for(int i=0;i<len;++i)
                {
                    int j=i+1;
                    while(j<len && curr[j]==curr[j-1]) j++;

                    int cnt=j-i;
                    divide*=fact[cnt];
                    i=j-1;
                }
                ans+=fact[len]/divide;
            }
            return;
        }

        helper(tiles, ind+1,n,st,curr);
        curr.push_back(tiles[ind]);
        helper(tiles,ind+1,n,st,curr);
        curr.pop_back();
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        ans=0;
        set<string>st;
        string curr="";
        helper(tiles,0,n,st,curr);
        return ans;
    }
};