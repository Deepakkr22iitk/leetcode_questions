class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int mx=*max_element(nums.begin(),nums.end()); // Maximum possible value of the bitwise AND from any subarray is the max value present 
        for(int i=0;i<n;++i)               // in the value itself as we need to set bits in all the elements of the subarry under considerartion 
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