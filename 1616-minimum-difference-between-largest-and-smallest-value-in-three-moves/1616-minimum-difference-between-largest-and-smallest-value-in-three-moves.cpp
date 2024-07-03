class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<4) return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int left=n-3;
        for(int i=0;i<n-(left-1);i++)
        {
            ans=min(ans,nums[i+left-1]-nums[i]);
        }
        return ans;
    }
};