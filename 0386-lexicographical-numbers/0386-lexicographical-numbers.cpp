class Solution {
public:
    bool dfs(int prev,int &n,vector<int>&ans)
    {
        ans.push_back(prev);
        for(int i=0;i<=9;++i)
        {
            int new_num=prev*10 + i;
            if(new_num<=n)
            {
                int flag=dfs(new_num,n,ans);
                if(flag==false) return false;
            }
        }
        return true;
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;++i)
        {
            if(i<=n) dfs(i,n,ans);
        }
        return ans;
    }
};