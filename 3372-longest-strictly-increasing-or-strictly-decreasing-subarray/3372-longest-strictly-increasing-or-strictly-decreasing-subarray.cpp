class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            int j=i+1;
            while(j<n && nums[j]>nums[j-1]) j++;
            
            ans=max(ans,(j-i));
            i=j-1;
        }
        
        for(int i=0;i<n;++i)
        {
            int j=i+1;
            while(j<n && nums[j]<nums[j-1]) j++;
            
            ans=max(ans,(j-i));
            i=j-1;
        }
        return ans;
    }
};