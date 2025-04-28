class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long ans=0;
        int i=0,j=0;
        long long total=0;
        while(j<n)
        {
            total+=nums[j];
            while(i<=j && total*(j-i+1)>=k) total-=nums[i++];
            ans+=(j-i+1);  // It's like the number of suitable subarrays ending at index 'j'...so that's why there are no duplicate 
            j++;             // count of single elements
        }
        return ans;
    }
};