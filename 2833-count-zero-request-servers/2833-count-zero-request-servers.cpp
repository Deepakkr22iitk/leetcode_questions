class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int len = logs.size(); 
        sort(logs.begin(), logs.end(), [&](vector<int> &a, vector<int> &b) {
            return a[1] < b[1]; 
        }); 
        vector<pair<int, int>> qu; 
        int q = queries.size(); 
        for(int i = 0; i < q; i++) qu.push_back({queries[i], i}); 
        sort(qu.begin(), qu.end()); 
        // sorted in ascending order we need to sort based on time actually
        unordered_map<int, int> mp; 
        vector<int> ans(q, 0); 
        int l = 0, r = 0; 
        for(int i = 0; i < q; i++) {
            int st = qu[i].first - x; 
            int en = qu[i].first; 

            while(r < len && logs[r][1] <= en) {
                mp[logs[r][0]]++; // insert server 
                r++; 
            }

            while(l < r && logs[l][1] < st) {
                mp[logs[l][0]]--; 
                if(mp[logs[l][0]] == 0) mp.erase(logs[l][0]); // remove from map 
                l++; 
            }

            ans[qu[i].second] = n - mp.size(); // total servers currently in range = mp size 
        }
        return ans; 
    }
};