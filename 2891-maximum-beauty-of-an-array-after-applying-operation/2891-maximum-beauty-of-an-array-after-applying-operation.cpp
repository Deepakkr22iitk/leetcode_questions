class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        for(int i=0;i<n;++i)
        {
            int idx=upper_bound(nums.begin(),nums.end(),nums[i]+2*k)-nums.begin();
            idx--;
            ans=max(ans,idx-i+1);
        }
        return ans;
    }
};