class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto &it:roads)
        {
            // node,steps
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        // dist,node
        pq.push({0,0});
        vector<long long> ways(n,0),dist(n,1e13);
        dist[0]=0;
        ways[0]=1;
        const long long mod = 1e9+7;
        while(!pq.empty())
        {
            int node=pq.top().second;
            long long currWeight=pq.top().first;
            pq.pop();
            
            for(auto &it:adj[node])
            {
                int adjNode=it.first;
                long long edgeWeight=it.second;
                // this is the first time I am coming with this short distance
                if(currWeight+edgeWeight < dist[adjNode])
                {
                    dist[adjNode]=currWeight+edgeWeight;
                    pq.push({currWeight+edgeWeight,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(currWeight+edgeWeight == dist[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
       
        if(dist[n-1]==1e13) return 0;
        return ways[n-1]%mod;
    }
};