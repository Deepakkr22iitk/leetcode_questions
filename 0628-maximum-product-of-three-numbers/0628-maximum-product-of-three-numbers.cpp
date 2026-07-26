class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans1=nums[0]*nums[1]*nums[2];
        if(n==3) return ans1;
        int ans2=nums[n-1]*nums[n-2]*nums[n-3];
        int ans3=nums[0]*nums[n-1]*nums[n-2];
        int ans4=nums[n-1]*nums[0]*nums[1];
        return max(ans1,max(ans2,max(ans3,ans4)));
    }
};