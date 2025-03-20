// We are trying to leverage the fact that with '&' operation, The existing value can remain same or it decreases.
class DisjointSet {
    vector<int>rank,parent;
    public:
    DisjointSet(int n) 
    {
        rank.resize(n+1);
        parent.resize(n+1);
        for (int i=0;i<=n;++i) parent[i]=i;
    }

    int findUPar(int node) 
    {
        if (node==parent[node]) return node;
        
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u, int v) 
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if (ulp_u==ulp_v) return;
        if (rank[ulp_u]<rank[ulp_v]) parent[ulp_u]=ulp_v;

        else if (rank[ulp_v] < rank[ulp_u]) parent[ulp_v]=ulp_u;

        else 
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n);
        vector<pair<int,int>>graph[n];
        map<long long,long long>comp_val;
        for(int i=0;i<edges.size();++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
            ds.unionByRank(u,v);
        }
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            int par=ds.findUPar(i);
            if(comp_val.find(par)!=comp_val.end()) continue;
            
            // These below code will run only for unique ultimate parents
            long long c=(1LL<<31)-1;
            vector<bool>vis(n);
        
            queue<int> q;
            q.push(par);
            vis[par]=true;

            while(!q.empty())
            {
                int curr=q.front(); 
                q.pop();

                for(auto &x:graph[curr])
                {
                    int p=x.first;
                    long long w=1LL*x.second;
                    c&=w;
                    if(vis[p]==false)
                    {
                        q.push(p);
                        vis[p]=1;
                    }
                }
            }

            // Upto this point 'c' would have performed all the '&' operation possible and Thus, It would be denoting minm possible value possible in this subtree
            if(c==((1LL<<31)-1)) comp_val[par]=0;
            else comp_val[par]=c;
        }
        
        for(int i=0;i<query.size();++i)
        {
            int st=query[i][0];
            int en=query[i][1]; 
            
            int par=ds.findUPar(st);
            int par2=ds.findUPar(en);
            
            if(par!=par2) ans.push_back(-1);
            
            else ans.push_back(comp_val[par]);
        }
        return ans;
    }
};