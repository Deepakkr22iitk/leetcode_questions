class Solution {
public:
    int validation(int mid,int k,int n,vector<int>&nums)
    {
        int taken=0;
        int prev=-2;
        for(int i=0;i<n;++i)
        {
            if(nums[i]>mid || prev==(i-1)) continue;
            prev=i;
            taken++;
        }
        return taken>=k;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        
        int ans=1;
        int l=1;
        int h=1e9;
        
        while(l<=h)
        {
            int mid =l+(h-l)/2;
            
            if(validation(mid,k,n,nums))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};