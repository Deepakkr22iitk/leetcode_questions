class Solution {
public:
    // Idea is simple, check for each of the values from '1' till the highest value present using Binary Search.
    bool predicate(vector<int>&nums,int mid,int &maxOperations)
    {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            if(nums[i]>mid)
            {
                cnt+=(nums[i]+mid-1)/mid;
                cnt--;        // It requires 1 less operation [9]-->[3,3,3] requires '2' operations only.
            }

            if(cnt>maxOperations) return false;
        }
        return (cnt<=maxOperations);
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int l=1,h=1e9;
        int ans=h;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(predicate(nums,mid,maxOperations))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};