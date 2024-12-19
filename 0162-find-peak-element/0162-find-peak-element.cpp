class Solution {
public:
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
        if(n==1) return 0;
        if(n==2) return nums[0]>nums[1]?0:1;
        int low=0,high=n-1,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(pred(nums,mid)>0)
            {
                ans=mid;
                break;
            }
            else if(pred(nums,mid)==0) 
            {
                if(nums[mid-1]<nums[mid])low=mid+1;
                else high=mid-1;
            }
            else 
            {
                if(nums[mid]>=nums[low]) low=mid+1;
                else high=mid-1;
            }
        }
        return ans;
    }
};