class Solution {
private: 
    vector<vector<int>> memo; 
    int getScore(vector<int> &piles, int pos, int m) {
        if(pos == piles.size()) return 0; // noscore 
        if(memo[pos][m] != -1) return memo[pos][m]; 
        int cur = 0; 
        int best = INT_MIN; 
        for(int i = pos; i < piles.size() && i < pos + 2 * m; i++) {
            cur += piles[i]; 
            best = max(best, cur - getScore(piles, i + 1, max(m, i - pos + 1))); 
        }

        return memo[pos][m] = best; 
    }
public:
    int stoneGameII(vector<int>& piles) {
        // find the net optimal difference 
        // a + b = piles.sum 
        // a- b = nedDiff 
        // a = (piles.sum + netDiff) / 2 
        memo = vector<vector<int>>(piles.size(), vector<int>(100, -1)); 
    
        int netDiff = getScore(piles, 0, 1); 
        int sum = 0; 
        for(int x: piles) sum+= x; 
        int a = (netDiff + sum) / 2; 
        return a;
    }
};