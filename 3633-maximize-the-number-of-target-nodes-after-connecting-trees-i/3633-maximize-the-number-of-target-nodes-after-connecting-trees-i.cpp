class Solution {
public:
    void dfs(vector<int>adj[],int st,int p,int edge,int &cnt,int &k)
    {
        if(edge<=k) cnt++;
        
        if(edge==k) return;
        for(auto &x:adj[st])
        {
            if(x!=p)
            {
                dfs(adj,x,st,edge+1,cnt,k);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size();
        int m=edges2.size();

        vector<int>adj1[n+1];
        vector<int>adj2[m+1];

        for(int i=0;i<n;++i)
        {
            int u=edges1[i][0];
            int v=edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(int i=0;i<m;++i)
        {
            int u=edges2[i][0];
            int v=edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int>dp(n+1,1); //To Keep track of count of nodes with edge length <=k in the first tree. Initialized with '1' because every node is already an answer to intself.

        if(k==0) return dp;

        for(int i=0;i<=n;++i)
        {
            int cnt=0;
            int edges=0;
            dfs(adj1,i,-1,edges,cnt,k);
            dp[i]=cnt;
        }

        // To keep track of the number of vertices at a distance less than equal to (k-1). 
        // Here '1' edge will cost because of connection establishment from tree1 to tree2. 
        // we then need to get the maximum as it's always wiser to connect tree1 with this point only.
        int mx=0;
        for(int i=0;i<=m;++i)     
        {
            int cnt=0;  // count of all the vertices less than equal to (k-1) distance.
            int edges=0;
            int new_k=k-1;
            dfs(adj2,i,-1,edges,cnt,new_k);  
            mx=max(mx,cnt);
        }

        vector<int>ans(n+1);
        for(int i=0;i<=n;++i) ans[i]=mx+dp[i];
        
        return ans;
    }
};