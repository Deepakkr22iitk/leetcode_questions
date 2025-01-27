class Solution {
public:
    // The idea is that 'u' is prerequisite of 'v' or not is simply isReachable[u][v];
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int len=prerequisites.size();
        vector<int>adj[numCourses];
        for(int i=0;i<len;++i)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<vector<bool>>isReachable(numCourses,vector<bool>(numCourses));
        for(int i=0;i<numCourses;++i)
        {
            isReachable[i][i]=1;
            queue<int>q;
            q.push(i);

            while(!q.empty())
            {
                auto temp=q.front();
                q.pop();

                for(auto &x:adj[temp])
                {
                    if(isReachable[i][x]==0) 
                    {
                        isReachable[i][x]=1;
                        q.push(x);
                    }
                }
            }
        }

        vector<bool>ans;
        for(auto &x:queries)
        {
            int u=x[0];
            int v=x[1];

            ans.push_back(isReachable[u][v]);
        }
        return ans;
    }
};