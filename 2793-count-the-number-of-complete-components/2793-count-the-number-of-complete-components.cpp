class Solution {
public:
    void dfs(vector<int>adj[],int &n,int st,vector<int>&vis,int& nodes,int p)
    {
        vis[st]=1;
        nodes++;
        
        for(auto x:adj[st])
        {
            if(x!=p)
            {
                if(vis[x]==0)
                {
                    dfs(adj,n,x,vis,nodes,st);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        int m=edges.size();
        vector<vector<int>>rk(n,vector<int>(n));
        for(int i=0;i<m;++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            rk[u][v]=1;
            rk[v][u]=1;
        }
        
        int ans=0;
        
        vector<int>vis(n);      
        for(int i=0;i<n;++i)          
        {
            if(vis[i]==0)
            {
                int nodes=0;
                vector<int>visit(n);    
                dfs(adj,n,i,visit,nodes,-1);
                int val=0;
                for(int l=0;l<n;++l)
                {
                    if(visit[l]==1)
                    {
                       vis[l]=1;
                       for(int j=0;j<n;++j)
                       {
                           if(visit[j]==1)
                           {
                                if(l==j) continue;
                                if(rk[l][j]==1) val++;
                           }
                       }   
                    }
                }
                val/=2;
                int rk=nodes*(nodes-1)/2;
                if(val==rk) ans++;
            }
        }
        return ans;
    }
};