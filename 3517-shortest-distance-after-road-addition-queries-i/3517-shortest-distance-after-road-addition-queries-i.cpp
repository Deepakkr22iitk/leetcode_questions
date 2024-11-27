class Solution {
public:
    int bfs(vector<int>adj[],int st,int en)
    {
        queue<int>q;
        q.push(st);
        vector<int>vis(en,-1);
        vis[st]=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();

            if(curr==(en-1)) return vis[en-1];

            for(auto &x: adj[curr])
            {
                if(vis[x]==-1)
                {
                    vis[x]=vis[curr]+1;
                    q.push(x);
                }
            }
        }
        return vis[en-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int len=queries.size();
        vector<int>ans;
        vector<int>adj[n];
        for(int i=0;i<(n-1);++i) adj[i].push_back(i+1);

        for(int i=0;i<len;++i)
        {
            int u=queries[i][0];
            int v=queries[i][1];

            adj[u].push_back(v);

            int curr_ans=bfs(adj,0,n);
            ans.push_back(curr_ans);
        }
        return ans;
    }
};