class Solution {
public:
    int findMin(vector<int>& nums) {
        // int n=nums.size();
        // if(n==1) return nums[0];
        // if(nums[n-1]>nums[0]) return nums[0];
        // if(n>1 && nums[n-2]>nums[n-1]) return nums[n-1];
        // int low=1,high=n-2;
        // while(low<=high)
        // {
        //     int mid=low+(high-low)/2;

        //     if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]) return nums[mid];
        //     else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]) return nums[mid+1];
        //     else
        //     {
        //         if(nums[mid]>nums[n-1])  low=mid+1;
        //         else high=mid;
        //     }
        // }
        // return 0;

        int start=0,end=nums.size()-1;
        
        while (start<end) {
            if (nums[start]<nums[end])
                return nums[start];
            
            int mid = (start+end)/2;
            
            if (nums[mid]>=nums[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return nums[start];
    }
};