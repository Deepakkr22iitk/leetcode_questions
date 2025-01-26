class Solution {
public:
    // Can see the editorial page for the diagram of our solution.
    // Two length cycles can be used with any_one or can also be used to different open components.
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int>inDegree(n);

        for(int i=0;i<n;++i) inDegree[favorite[i]]++;

        // Topological sorting to remove non-cycle nodes
        queue<int>q;
        for(int i=0;i<n;++i)
        {
            if(inDegree[i]==0) q.push(i);
        }

        vector<int>depth(n,1);   // Represents the longest path from any starting node to this particular node.
        while(!q.empty())
        {
            int curr_node=q.front();
            q.pop();

            int next_node=favorite[curr_node];
            depth[next_node]=max(depth[next_node], depth[curr_node]+1);

            if(--inDegree[next_node]==0) q.push(next_node);
        }

        int longestCycle=0;
        int twoCycles=0;

        //Detect cycles
        for(int i=0;i<n;++i)
        {
            if(inDegree[i]>0)
            {
                int cycle_len=0;
                int curr=i;
                while(inDegree[curr]!=0)
                {
                    inDegree[curr]=0;
                    cycle_len++;
                    curr=favorite[curr];
                }

                if(cycle_len==2) twoCycles+=(depth[i]+depth[favorite[i]]); // Because both nodes can invite the maximum number of people based on their depths.

                else longestCycle=max(longestCycle, cycle_len);
            }
        }

        return max(longestCycle,twoCycles);
    }
};