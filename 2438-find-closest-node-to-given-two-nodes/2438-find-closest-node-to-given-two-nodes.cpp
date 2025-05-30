class Solution {
public:
    void dfs(int node,int dist, vector<int>&edges, vector<int>& dis) 
    {
        if(node!=-1 && dis[node]==-1) 
        {
            dis[node]=dist; 
            dfs(edges[node],dist+1,edges,dis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        if(node1==node2) return node1;
        int ans=-1, min_dist=INT_MAX;
        vector<int>dist1(n,-1),dist2(n,-1); //Stores the distance to reach each of the other nodes starting from node1 and node2 respectively.
        dfs(node1,0,edges,dist1);
        dfs(node2,0,edges,dist2);

        for(int i=0;i<n;++i) 
        {
            if(min(dist1[i],dist2[i])>=0 && max(dist1[i], dist2[i])<min_dist) 
            {
                min_dist=max(dist1[i], dist2[i]);
                ans=i;
            }
        }
        return ans;
    }
};