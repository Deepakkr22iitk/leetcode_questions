class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=nums[0];
        int count = 0;
        for(int i = 0;i<nums.size();++i)
        {
            if(count==0) element=nums[i];
            count+=(element==nums[i])?1:-1;
        }
        return element;
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // return nums[n/2];
    }
};