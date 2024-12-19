class Solution {
public:
    int findSumAfterDiv(vector<int>& v,int n,int div){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=((v[i]+div-1)/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(findSumAfterDiv(nums,nums.size(),mid)<=threshold)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};