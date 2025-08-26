class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,0);
        dp1[0]=max(nums[0],0);
        int ind=1;
        int selecting=nums[0];
        while(ind<n)
        {
            dp1[ind]=max(dp1[ind-1]+nums[ind],nums[ind]);
            selecting=max(selecting,dp1[ind]);
            ind++;
        }

        vector<int> dp2(n,0);
        dp2[0]=min(0,nums[0]);
        int not_selecting=-nums[0];
        ind=1;
        int total=nums[0];
        while(ind<n)
        {
            dp2[ind]=max(dp2[(ind-1)]-nums[ind],-nums[ind]);
            not_selecting=max(not_selecting,dp2[ind]);
            total+=nums[ind];
            ind++;
        }

        // if(total+not_selecting==0) return selecting;
        return max(selecting,total+not_selecting);
    }
};