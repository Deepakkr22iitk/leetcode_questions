class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> zeros;
        int ind=0;
        long long ans=0;
        while(ind<n)
        {
            if(nums[ind]==0)
            {
                int start=ind;
                int end=start+1;
                while(end<n && nums[end]==0) end++;
                long long length=1ll*(end-start);
                ans+=(length*(length+1))/(1ll*2);
                ind=end-1;
            }
            ind++;
        }
        return ans;
    }
};