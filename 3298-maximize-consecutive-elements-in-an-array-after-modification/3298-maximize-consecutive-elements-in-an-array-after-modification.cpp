class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int maxLen = 0;

        for (int x : nums) {
            int v1 = dp[x] + 1;
            int v2 = dp[x - 1] + 1;

            dp[x + 1] = max(dp[x + 1], v1);
            dp[x] = max(dp[x], v2);

            maxLen = max({maxLen, dp[x + 1], dp[x]});
        }

        return maxLen;
    }
};