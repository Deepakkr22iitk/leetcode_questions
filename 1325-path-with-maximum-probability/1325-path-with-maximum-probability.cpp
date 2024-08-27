class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }

        vector<double>ans(n,0.0);
        ans[start]=1;
        queue<pair<int,double>>q;
        q.push({start,1.0});
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int node=temp.first;
            double val=temp.second;

            for(auto &x:adj[node])
            {
                if(ans[x.first]<(val*x.second))
                {
                    ans[x.first]=(val*x.second);
                    q.push({x.first,ans[x.first]});
                }
            }
        }
        return ans[end];
    }
};