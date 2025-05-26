class Solution {
public:
    vector<int>topo;
    bool dfs(int i,vector<int>adj[],int n,vector<int>&vis,vector<int>&pathvis)
    {
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:adj[i])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,n,vis,pathvis)) return true;
            }
            if(pathvis[it]==1) return true;
        }
        pathvis[i]=0;
        topo.push_back(i);
        return false;
    }
    bool check_cycle(int n,vector<int>adj[])
    {
        vector<int>vis(n),pathvis(n);

        for(int i=0;i<n;++i)
        {
            if(vis[i]==0)
            {
                bool temp=dfs(i,adj,n,vis,pathvis);
                if(temp==true) return true;
            }
        }
        return false;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int>adj[n];
        for(int i=0;i<edges.size();++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }

        if(check_cycle(n,adj)) return -1;

        vector<vector<int>>dp(n, vector<int>(26));
        int maxcolor=-1;
        for(int k=topo.size()-1;k>=0;--k)  // We're processing it in reverse order as in the 'topo' vector elements would be stored in 
        {                                  // reverse fashion e.g., [1,4,3,2,0]
            int i=topo[k];
            dp[i][colors[i]-97]++;
            maxcolor=max(maxcolor, dp[i][colors[i]-97]);
            
            for(int &x:adj[i]) 
            {
                for(int col=0;col<26;++col) if(dp[x][col]<dp[i][col]) dp[x][col]=dp[i][col];
            }
        }
        return maxcolor;
    }
};