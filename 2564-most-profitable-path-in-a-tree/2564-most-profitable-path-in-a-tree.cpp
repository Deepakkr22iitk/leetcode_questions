class Solution {
public:
    //  The idea is to change the 'amount' vector for Alice based on the level of traversal.
    int mxm=INT_MIN;          // Find out the maximum value to reach any of the leaf node
    void minfromroot(vector<int>tree[],int sv,vector<int>&amount,int ans,vector<bool>&pk)
    {
        ans+=amount[sv];
        pk[sv]=true;
        if(tree[sv].size()==1 && sv!=0) mxm=max(ans,mxm);

        for(auto &x:tree[sv])
        {
            if(!pk[x]) minfromroot(tree,x,amount,ans,pk);
        }
        ans-=amount[sv];
    } 
    
    void findparent(vector<int>tree[],vector<int>&parent,int sv,int p,vector<bool>&vis,vector<int>&level)
    {
            vis[sv]=true;
            parent[sv]=p; 
            if(sv!=0) level[sv]=level[p]+1;
            for(int &x:tree[sv]) 
            {
                if(vis[x]==0) findparent(tree,parent,x,sv,vis,level);
            }  
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int>tree[n];
        for(int i=0;i<edges.size();++i)
        {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        
        mxm=INT_MIN;
        vector<bool>vis(n);
        vector<int>parent(n);
        vector<int>level(n);
        parent[0]=0;
        level[0]=0;
        findparent(tree,parent,0,0,vis,level);
        
        // Now, we are trying to change the amount vector for Alice.
        int curr=0;
        while(bob!=0)
        {
            if(level[bob]>curr) amount[bob]=0;    // For Alice, Bob has already opened this gate so, '0'

            if(level[bob]==curr) amount[bob]/=2;
            bob=parent[bob];
            curr++;
        }
        
        int ans=0;
        vector<bool>pk(n);
        minfromroot(tree,0,amount,ans,pk);
        return mxm;    
    }
};