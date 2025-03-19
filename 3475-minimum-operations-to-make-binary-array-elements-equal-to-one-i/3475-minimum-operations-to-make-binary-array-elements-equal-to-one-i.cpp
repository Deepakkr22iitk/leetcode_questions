class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int op=0;

        int j=0;
        while(j<=(n-3))
        {
            if(nums[j]==0)
            {
                op++;
                nums[j+1]=1-nums[j+1];
                nums[j+2]=1-nums[j+2];
            }
            j++;
        }
        if(nums[n-1]==0 || nums[n-2]==0) return -1;
        return op;
    }
};