#define pii pair<int, int>
#define F first
#define S second

vector<vector<int>> neighbors = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

struct DSU {
    vector<int> par, sz;
    
    DSU (int n) {
        par.resize(n);
        sz.resize(n, 1);
        for (int j = 0; j < n; j ++) par[j] = j;
    }
    
    int Leader (int x) {
        if (x == par[x]) return x;
        return (par[x] = Leader(par[x]));
    }
    
    void Merge (int x, int y) {
        x = Leader(x);
        y = Leader(y);
        
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        
        sz[y] += sz[x];
        par[x] = y;
    }
};

class Solution {
    
    vector<vector<int>> DistanceToEveryNode (const vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        queue<pii> q;
        
        for (int r = 0; r < rows; r ++) {
            for (int c = 0; c < cols; c ++)
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
        }
        
        while (!q.empty()) {
            pii cell = q.front();
            q.pop();
            
            for (auto i : neighbors) {
                int r = cell.F + i[0];
                int c = cell.S + i[1];
                
                bool is_valid = (r >= 0 && r < rows) && (c >= 0 && c < cols);
                bool is_visited = (is_valid && dist[r][c] != -1);
                
                if (!is_valid || is_visited) continue;
                q.push({r, c});
                dist[r][c] = dist[cell.F][cell.S] + 1;
            }
        }
        
        return dist;
    }
    
    bool IsValid (int max_dist, const vector<vector<int>>& grid, const vector<vector<int>>& dist) {
        int n = grid.size();
        
        if (dist[0][0] < max_dist) return false;
        
        queue<pii> q;
        q.push({0, 0});
        
        vector<vector<bool>> visited (n, vector<bool>(n, false));
        visited[0][0] = true;
        
        while (!q.empty()) {
            pii cell = q.front();
            q.pop();
            if (cell.F == n-1 && cell.S == n-1) return true;
            
            for (auto i : neighbors) {
                int r = cell.F + i[0];
                int c = cell.S + i[1];
                
                bool is_valid = (r >= 0 && r < n) && (c >= 0 && c < n);
                bool is_visited = (is_valid && visited[r][c]);
                
                if (!is_valid || is_visited) continue;
                
                visited[r][c] = true;
                
                if (dist[r][c] < max_dist) continue;                
                q.push({r, c});
            }
        }
        
        return false;
    }
    
    int Val (pii cell, int n) {
        return (cell.F * n + cell.S);
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> dist = DistanceToEveryNode(grid);
        
        /*
        // Approach 1 - Binary Search
        
        int l = 0, r = 401;
        while (l < r) {
            int m = (l+r) >> 1;
            
            if (IsValid (m+1, grid, dist)) l = m+1;
            else r = m;
        }
        return l;
        */
        
        // Approach 2 - DSU
        
        int n = grid.size();
        if (n == 1) return 0;
        
        vector<pair<int, pii>> cell_and_dist;
        
        for (int r = 0; r < n; r ++) {
            for (int c = 0; c < n; c ++) 
                cell_and_dist.push_back({dist[r][c], {r, c}});
        }
        sort (cell_and_dist.begin(), cell_and_dist.end());
        
        int ind = n*n - 1;
        DSU dsu(n*n);
        vector<vector<bool>> active(n, vector<bool>(n, false));
        
        for (int result = 401; result >= 0; result --) {
            // Keep merging :)
            while (ind >= 0 && cell_and_dist[ind].F >= result) {
                pii cell = cell_and_dist[ind].S;
                active[cell.F][cell.S] = true;
                
                for (auto i : neighbors) {
                    int r = cell.F + i[0];
                    int c = cell.S + i[1];
                    
                    bool is_valid = (r >= 0 && r < n) && (c >= 0 && c < n);
                    if (!is_valid) continue;
                    
                    if (active[r][c]) dsu.Merge (Val({r, c}, n), Val(cell, n));
                }
                ind --;
            }
            
            if (dsu.Leader(0) == dsu.Leader(n*n - 1)) return result;
        }
        
        return -1;
    }
};