class Solution {
public:
    // same as Allocate Minimum Pages gfg
    // and 1011. Capacity To Ship Packages Within D Days (leetcode)
    int numberOfSubArraysByKeepingLimit(vector<int>& v,int n,int limit,int s)   {
        int count=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(v[i]>limit) return false;
            if(sum+v[i]>limit){
                count++;
                sum=v[i];
            }
            else{
                sum+=v[i];
            }
        }
        return count<=s;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<n;i++){
            high+=nums[i];
        }
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(numberOfSubArraysByKeepingLimit(nums,n,mid,k)==false){
                low=mid+1;
            }
            else {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};