class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int res=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mn=nums[0];
        for(int i=0;i<n;++i)
        {
            if((nums[i]-mn)>k)
            {
                res++;
                mn=nums[i];
            }
        }
        res++;
        return res;
    }
};