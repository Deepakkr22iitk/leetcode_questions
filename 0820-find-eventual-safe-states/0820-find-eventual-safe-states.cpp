class Solution {
public:
    // bool dfs(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&path,vector<int>&check)
    // {
    //     vis[node]=1;
    //     path[node]=1;
        
    //     // traverse through the adjacent node
    //     for(auto it : graph[node])
    //     {
    //         // when the node is not visited
    //         if(!vis[it])
    //         {
    //             vis[it]=1;
    //             if(dfs(it,graph,vis,path,check)==true)
    //             {
    //                 check[it] = 0;
    //                 return true;
    //             }
    //         }
    //         // if the node has been previous visited
    //         // but it has to be visited on the same path
    //         else if(path[it]) 
    //         {
    //             check[it] = 0;
    //             return true;
    //         }
    //     }
        
    //     // going back from the same path
    //     check[node]=1;
    //     path[node] = 0;
    //     return false;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        // vector<int> vis(v,0);
        // vector<int> path(v,0);
        // vector<int> check(v,0);
        // vector<int> ans;
        // for(int i=0;i<v;i++)
        // {
        //     if(!vis[i]){
        //         dfs(i,graph,vis,path,check);
        //     }
        // }
        
        // for(int i =0;i<v;i++)
        // {
        //     if(check[i]) ans.push_back(i);
        // }
        // return ans;

        vector<int> adjRev[v];
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++)
        {
            // i --> it
            // it --> i
            for(auto it : graph[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++)
        {
           if(indegree[i]==0)
           {
               q.push(i);
           }
        }
        
        vector<int> safeNodes;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(auto it : adjRev[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        
        return safeNodes;
    }
};