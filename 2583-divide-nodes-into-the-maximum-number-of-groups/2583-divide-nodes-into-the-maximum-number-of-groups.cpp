class Solution {
public:
    // If the graph is not bipartite. Then, its never possible to assign groups else the answer is summation of diameter of all the components.
    // The maxm dist1 and then maxm dist2 method fails in case of graph but works very fine in case of tree.
    // so, As per the constraints allowed, I'll precompute the max_depth for each of the node and then while evaluating for any component
    // I'll take out the maxm value among all of the nodes.
    bool bipartite(int st,vector<int>adj[],vector<int>&color)
    {
        queue<int>q;
        q.push(st);
        color[st]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto &x:adj[node])
            {
                if(color[x]==-1)
                {
                    color[x]=!color[node];
                    q.push(x);
                }
                else if(color[x]==color[node]) return false;
            }
        }
        return true;
    }

    int bfs(vector<int>adj[],int st,int n)
    {
        queue<int>q;
        q.push(st);
        vector<bool>vis(n+1);
        vis[st]=1;
        int level=0;

        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;++i)
            {
                auto node=q.front();
                q.pop();

                for(auto &x:adj[node])
                {
                    if(vis[x]==0)
                    {
                        vis[x]=1;
                        q.push(x);
                    }
                }
            }
            level++;
        }
        return level;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        int len=edges.size();
        for(int i=0;i<len;++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n+1,-1);
        for(int i=1;i<=n;++i)
        {
            if(color[i]==-1)
            {
                if(bipartite(i,adj,color)==false) return -1;
            }
        }

        vector<int>mx_dist(n+1);
        for(int node=1;node<=n;++node)
        {
            int ans=bfs(adj,node,n);
            mx_dist[node]=ans;
        }

        for(auto &x:mx_dist) cout<<x<<" ";
        cout<<"\n";

        int ans=0;
        vector<int>vis(n+1);

        for(int i=1;i<=n;++i)
        {
            if(vis[i]==0)
            {
                queue<int>q;
                q.push(i);
                vis[i]=1;
                int curr_ans=mx_dist[i];
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();

                    for(auto &x:adj[node])
                    {
                        if(vis[x]==0)
                        {
                            vis[x]=1;
                            curr_ans=max(curr_ans,mx_dist[x]);
                            q.push(x);
                        }
                    }
                }
                ans+=curr_ans;
            }
        }
        return ans;
    }
};