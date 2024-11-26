class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans = -1;
        int cnt = 0;
        vector<int> indegree(n);
        for(auto &x: edges) indegree[x[1]]++;
        for(int i=0;i<n;++i) 
        {
            if(indegree[i]==0) 
            {
                cnt++; 
                ans=i; 
            }
        }
        if(cnt>1) return -1;      // If more than one champion, simply return -1
        return ans;
    }
};