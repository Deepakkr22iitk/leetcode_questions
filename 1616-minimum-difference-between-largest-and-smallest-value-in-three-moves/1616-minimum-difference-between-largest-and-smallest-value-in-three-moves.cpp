class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        // when n<=3 we can make each element of the vector equal.
        if(n<4) return 0; 
        sort(nums.begin(),nums.end());
        // in other cases where n>3 we need to first sort the vector
        int ans=INT_MAX;
        int left=n-3-1;
        for(int i=0;i<n-left;i++)
        {
            ans=min(ans,nums[i+left]-nums[i]);
        }
        return ans;
    }
};