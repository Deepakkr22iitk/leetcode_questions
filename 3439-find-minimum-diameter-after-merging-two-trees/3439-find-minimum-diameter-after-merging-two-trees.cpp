class Solution {
public:
    void dfs(vector<int>adj[],int st,int p,int val,vector<int>&dist)
    {
        dist[st]=val;
        for(auto &x:adj[st])
        {
            if(x!=p)
            {
                dfs(adj,x,st,val+1,dist);
            }
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();  // But the number of vertices will be from [0, n+1);
        int m=edges2.size();  // Same number of vertices will be from [0,m+1)

        int no_vert1=n+1;
        int no_vert2=m+1;

        vector<int>adj1[no_vert1];
        vector<int>adj2[no_vert2];

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

        vector<int>dist1(n+1),dist2(n+1);
        int val=0;
        dfs(adj1,0,-1,val,dist1);

        int mx_dist=0,mx_ind=0;
        for(int i=0;i<(n+1);++i)
        {
            if(dist1[i]>mx_dist)
            {
                mx_dist=dist1[i];
                mx_ind=i;
            }
        }
        val=0;
        dfs(adj1,mx_ind,-1,val,dist2);

        mx_dist=0,mx_ind=0;
        for(int i=0;i<(n+1);++i)
        {
            if(dist2[i]>mx_dist)
            {
                mx_dist=dist2[i];
                mx_ind=i;
            }
        }
        val=0;
        dfs(adj1,mx_ind,-1,val,dist1); // After this second call, dist1 is having the distance from terminal end point

        val=0;

        //cout<<mx_dist<<" "<<mx_ind<<"\n";

        vector<int>dist3(m+1),dist4(m+1);
        dfs(adj2,0,-1,val,dist3);

        int mx_dist2=0,mx_ind2=0;
        for(int i=0;i<(m+1);++i)
        {
            if(dist3[i]>mx_dist2)
            {
                mx_dist2=dist3[i];
                mx_ind2=i;
            }
        }

        val=0;
        dfs(adj2,mx_ind2,-1,val,dist4);

        mx_dist2=0,mx_ind2=0;
        for(int i=0;i<(m+1);++i)
        {
            if(dist4[i]>mx_dist2)
            {
                mx_dist2=dist4[i];
                mx_ind2=i;
            }
        }

        val=0;
        dfs(adj2,mx_ind2,-1,val,dist3);// Now dist3 is having the required distance value from the terminal


        int mn_terminal_dist=mx_dist2;
        for(int i=0;i<(m+1);++i)
        {
            int curr=max(dist3[i],dist4[i]);
            mn_terminal_dist=min(mn_terminal_dist,curr);
        }

        int ans=1e9;
        for(int i=0;i<(n+1);++i)
        {
            int curr=max(dist1[i],dist2[i])+mn_terminal_dist+1;
            ans=min(ans,curr);
        }
        int final_ans=max(mx_dist,mx_dist2);
        final_ans=max(final_ans,ans);
        return final_ans;
    }
};