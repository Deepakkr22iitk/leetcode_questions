// The idea is that precompute sizes of all the different originally connected components and then Traverse the matrix and whenever we
// encounter a '0'. we'll check for all it's four sided neighbours and the potential 'ans' can be the summation of sizes of the neighboring
// ultimate parents.

class DisjointSet {    
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0;i<=n;++i) 
        {
            parent[i]=i;
            size[i]=1;
        }
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
        if(ulp_u==ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]) parent[ulp_u] = ulp_v;

        else if(rank[ulp_v]<rank[ulp_u]) parent[ulp_v]=ulp_u;
        else 
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) 
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if (ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]) 
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else 
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int cnt=0;
        int n=grid.size();
        DisjointSet ds(n*n);

        vector<int>dr={1,0,-1,0,1};
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                    for(int ind=0;ind<4;++ind)
                    {
                        int newx=i+dr[ind];
                        int newy=j+dr[ind+1];
                        if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]==1)
                        {
                            int cell1=i*n+j;
                            int cell2=newx*n+newy;
                            ds.unionBySize(cell1,cell2);
                        }  
                    }
                }
            }
        }
        if(cnt==(n*n)) return cnt;

        int ans=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==0)
                {
                    set<int>st;   // we are using 'set' as two neighboring of any '0' can have the same ultimate parent. so, we should count them only once.
                    for(int ind=0;ind<4;++ind)
                    {
                        int newx=i+dr[ind];
                        int newy=j+dr[ind+1];
                        if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]==1)
                        {
                            int cell1=newx*n+newy;
                            st.insert(ds.findUPar(cell1));
                        }  
                    }
                    int temp=0;
                    for(auto x:st)
                    {
                        temp+=ds.size[x];
                    }
                    temp++;
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};