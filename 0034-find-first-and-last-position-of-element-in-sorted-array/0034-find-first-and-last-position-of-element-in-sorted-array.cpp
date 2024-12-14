class Solution {
public:
    int Occurence(vector<int> &nums,int target)
    {
        int n=nums.size();
        int ans=n;
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                high=mid-1;
            } 
            else low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=Occurence(nums,target);
        if(first==n || (first<n && nums[first]!=target)) return {-1,-1};
        int last=Occurence(nums,target+1);

        return {first,last-1};
    }
};