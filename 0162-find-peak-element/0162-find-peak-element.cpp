class Solution {
public:
    // here we are using a predicate fxn such that it will increase if nums[mid]>neighbour
    // also we are checking whether the neighbour is existing or not
    int pred(vector<int> &nums,int mid)
    {
        int ans=0;
        if(mid>0) 
        {
            if(nums[mid]>nums[mid-1]) ans++;
            else ans--;
        }
        if(mid<nums.size()-1)
        {
            if(nums[mid]>nums[mid+1]) ans++;
            else ans--;
        }
        return ans;
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        // tackling the 2 base cases
        if(n==1) return 0;
        if(n==2) return nums[0]>nums[1]?0:1;
        int low=0,high=n-1,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            // predicate will give > 0 i.e. either 1(edge case) or 2(somewhere is the middle)
            if(pred(nums,mid)>0)
            {
                ans=mid;
                break;
            }
            // if predicate == 0 means middle is in between increasing or decreasing
            //                     \                   /
            // ans will be on left  \<----(middle)--->/   ans will be on right {low=mid+1}
            //                       \               / 
            else if(pred(nums,mid)==0) 
            {
                if(nums[mid-1]<nums[mid])low=mid+1;
                else high=mid-1;
            }
            // checking with low since low can be == mid so nums[mid]>=nums[low] 
            // ans will be on right side
            else 
            {
                if(nums[mid]>=nums[low]) low=mid+1;
                else high=mid-1;
            }
        }
        return ans;
    }
};