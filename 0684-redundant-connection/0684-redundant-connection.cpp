// The idea behind DSU is that each node is in its own a separate set. As we go through the edges, 
// we perform a union operation that merges the sets of the two connected nodes. This helps us track 
// which nodes are in the same component. If, during this process, we encounter an edge where the two 
// nodes are already in the same component (i.e., they share the same representative), we know that adding this 
// edge would create a cycle, so it’s redundant and can be safely discarded.

class Solution {
public:
    class DSU{
        vector<int>size;
        vector<int>parent;

        public:
        DSU(int sz)
        {
            for(int i=0;i<sz;++i) 
            {
                parent.push_back(i);
                size.push_back(1);
            }    
        }

        int u_parent(int node)
        {
            if(parent[node]==node) return node;

            return parent[node]=u_parent(parent[node]);
        }

        bool union_by_sz(int a,int b)
        {
            int par_a=u_parent(a);
            int par_b=u_parent(b);

            if(par_a==par_b) return false;

            if(size[par_a]>size[par_b])
            {
                parent[par_b]=par_a;
                size[par_a]+=size[par_b];
            }
            else
            {
                parent[par_a]=par_b;
                size[par_b]+=size[par_a];
            }
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        n++;                  // Since edges are 1 based indexed
        DSU d(n);

        for(auto &x:edges)
        {
            if(d.union_by_sz(x[0],x[1])==false) return x;
        }

        return {};
    }
};