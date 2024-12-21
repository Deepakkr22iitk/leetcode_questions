class Solution {
public:
    // The idea is simple for each of the node check the (summation%k) from each of the child if its equal to '0' then increase
    // the components count.
    long long helper(vector<int> adj[],int n,vector<int>&values,int k,int st,int p,int& ans)
    {
        long long val=1LL*values[st];
        for(auto &x:adj[st])
        {
            if(x!=p)
            {
                long long temp=helper(adj,n,values,k,x,st,ans);
                if(temp==0) ans++;
                
                val+=temp;
            }
        }
        val=val%k;
        return val;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>adj[n+1];
        int m=edges.size();
        for(int i=0;i<m;++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans=1;
        helper(adj,n,values,k,0,-1,ans);
        return ans;
    }
};