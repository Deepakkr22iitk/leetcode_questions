class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        // find the next power of 2 which is greater than n
        int ans = 1;
        while (ans <= n)
            ans <<= 1;

        return ans;
    }
};