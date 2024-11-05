class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1]) count1++;
        }
        if(count1==1)
        {
            return nums[n-1]<=nums[0];
        }
        else if(count1==0)
        {
            return nums[n-1]>=nums[0];
        }
        else return false;
    }
};