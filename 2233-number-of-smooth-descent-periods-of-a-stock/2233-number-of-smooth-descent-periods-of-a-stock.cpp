class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int cnt = 1;
        
        for(int i = 0; i < prices.size(); i++){
            // Handle the first element separately or simply skip checking prev
            if(i == 0){
                ans += cnt;
                continue;
            }
            
            // Check if the current price is exactly 1 less than the previous
            if(prices[i] == prices[i-1] - 1){
                cnt++;
            } else {
                cnt = 1; // Reset sequence length
            }
            
            ans += cnt; // Add the number of subarrays ending at current index
        }
        
        return ans;
    }
};