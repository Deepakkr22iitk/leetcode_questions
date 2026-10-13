class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &it: nums){
            if(it < 0){
                it = -it;
            }
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0,high = n-1;
        long long sol = 0;
        while(low < high){
            sol = sol + (1ll * nums[high] * nums[high]) - (1ll * nums[low] * nums[low]);
            low++;
            high--;
        }
        if(low == high){
            sol = sol + (1ll * nums[low] * nums[low]);
        }
        return sol;
    }
};