class Solution {
public:
    // Given a node, From a child contribution in even_nodes will be the cnt_of odd in child node and contribution in odd_nodes 
    // will be cnt_of_even node in child. Also, +1 contribution in the cnt_of even nodes considering the self node too. 
    //
    // Consider the Sample1:
    // After the first dfs call tree2:
    // [0]-->{3,5}
    // [1]-->{3,1}
    // [2]-->{1,1}
    // [3]-->{1,0}
    // [4]-->{1,2}
    // [5]-->{1,0}
    // [6]-->{1,0}
    // [7]-->{1,0}

    // Now after Rerooting:
    // [0]-->{3,5}
    // [1]-->{4,4}  
    // [2]-->{5,3}  [3-1, 5-1] == [2,4] Now adding the contribution of child [4+0+1, 2+1]==[5,3]
    // [3]-->{5,3}
    // [4]-->{3,5}
    // [5]-->{5,3}
    // [6]-->{5,3}
    // [7]-->{3,5}
    pair<int,int> dfs(vector<int>adj[],int st,int p,vector<pair<int,int>>&dp)
    {
        int curr_ev=1;
        int curr_odd=0;

        for(auto &x:adj[st])
        {
            if(x!=p)
            {
                auto temp=dfs(adj,x,st,dp);
                int even_cnt=temp.first;
                int odd_cnt=temp.second;

                curr_ev+=odd_cnt;
                curr_odd+=even_cnt;
            }
        }

        dp[st]={curr_ev,curr_odd};
        return {curr_ev,curr_odd};
    }

    void rerooting_and_computing(vector<int>adj[],int st,int p,vector<pair<int,int>>&dp)
    {
        if(p!=-1)
        {
            int p_ev=dp[p].first;
            int p_odd=dp[p].second;
            
            int my_ev=dp[st].first;
            int my_odd=dp[st].second;

            p_ev-=my_odd;
            p_odd-=my_ev;

            int new_ev=p_odd;
            int new_odd=p_ev;
            for(auto &x:adj[st])
            {
                if(x!=p)
                {
                    auto temp=dp[x];
                    int child_ev=temp.first;
                    int child_odd=temp.second;

                    new_ev+=child_odd;
                    new_odd+=child_ev;
                }
            }

            dp[st]={new_ev+1,new_odd};
        }

        for(auto &x:adj[st])
        {
            if(x!=p) rerooting_and_computing(adj,x,st,dp);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();  // But the number of vertices will be from [0, n+1);
        int m=edges2.size();  // Same number of vertices will be from [0,m+1)

        vector<int>adj1[n+1];
        vector<int>adj2[m+1];

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

        vector<pair<int,int>>dp1(n+1); // To keep track of cnt of even and odd distance nodes {even, odd} in tree1

        auto final_cnt=dfs(adj1,0,-1,dp1);
        
        rerooting_and_computing(adj1,0,-1,dp1);  //computing the cnt of even and odd for each of the nodes present in the tree1. We are using 
        // rerooting technique to build our 'dp' for each of the nodes considering the time constraints.

        vector<pair<int,int>>dp2(m+1); // Keep track of cnt_of even and odd distance nodes {even,odd} in tree2

        final_cnt=dfs(adj2,0,-1,dp2);

        rerooting_and_computing(adj2,0,-1,dp2); 

        int mx_odd_tree2=0;   // Since, we are expected to connect tree1 to tree2, any way one of the edge will be used for connection 
        // b/w i'th node and the connection in tree2, so we need max odd count from tree2 to make the path count even.
        for(int i=0;i<(m+1);++i)
        {
            int curr=dp2[i].second;
            mx_odd_tree2=max(mx_odd_tree2,curr);
        }

        // for(int i=0;i<(n+1);++i) cout<<dp1[i].first<<" "<<dp1[i].second<<"\n";

        // cout<<"dusra\n";
        // for(int i=0;i<(m+1);++i) cout<<dp2[i].first<<" "<<dp2[i].second<<"\n";

        vector<int>ans(n+1);

        for(int i=0;i<(n+1);++i)
        {
            int curr=dp1[i].first+mx_odd_tree2;
            ans[i]=curr;
        }
        return ans;
    }
};