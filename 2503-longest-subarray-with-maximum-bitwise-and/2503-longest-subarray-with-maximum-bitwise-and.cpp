class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;++i)
        {
            if(nums[i]==mx)
            {
                int j=i+1;
                while(j<n && nums[j]==mx)
                {
                    j++;
                }
                ans=max(ans,j-i);
                i=j-1;
            }
        }
        return ans;
    }
};