class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,h=nums[n-1]-nums[0];
        int ans=h;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int cnt=0,left=0;
            for(int right=0;right<n;++right)
            {
                while((nums[right]-nums[left])>mid) left++;

                cnt+=(right-left);
            }
            if(cnt>=k)
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};