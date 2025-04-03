class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> left(n, 0), right(n, 0); 
        int maxl = INT_MIN, maxr = INT_MIN;
        // getting the maximum number till that point(including) from left 
        for(int i = 0; i < n ; i++){
            if(nums[i] > maxl){
                maxl = nums[i];
            }
            left[i] = maxl;
        }
        // getting the maximum number till that point(including) from right
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] > maxr){
                maxr = nums[i];
            }
            right[i] = maxr;
        }
        // Calculating the triplet at that point
        vector<long long> ans;
        for(int i = 1; i < n - 1; i++){
            long long x = (left[i-1] - nums[i])*right[i+1];
            if(x < 0) x = 0;
            ans.push_back(x);
        }
        // sorting nd then getting the last index
        sort(ans.begin(), ans.end());
        return ans[ans.size() - 1];
    }
};