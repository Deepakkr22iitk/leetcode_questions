class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=nums[0];
        int temp=nums[0];
        int n=nums.size();
        for(int i=1;i<n;++i)
        {
            if(nums[i]>nums[i-1])
            {
                temp+=nums[i];
            }
            else 
            {
                ans=max(ans,temp);
                temp=nums[i];
            }
        }
        ans=max(ans,temp);
        return ans;
    }
};