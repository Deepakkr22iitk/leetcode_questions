class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        int ind=0,maxi=nums[0];
        while(ind<n && ind<=maxi)
        {
            maxi=max(maxi,ind+nums[ind]);
            ind++;
        }
        return ind==n;
    }
};