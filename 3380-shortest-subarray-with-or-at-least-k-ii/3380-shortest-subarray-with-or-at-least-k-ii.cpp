class Solution {
public:
    // The idea is to use sliding window 
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0) return 1;
        long long val=0;
        int n=nums.size();
        int ans=INT_MAX;
        int i=0;
        int j=0;
        vector<int>pre(32);
        while(j<n)
        {
            val|=(1LL*nums[j]);
            long long temp=1LL*nums[j];
            for(int l=0;l<32;++l)            // Taking the contribution of this particular element on bits
            {
                int curr=(1&temp);
                temp/=2;
                if(curr>0) pre[l]++;  
            }
            
            while(val>=(1LL*k))    // while the condition is valid, we can take this particular length 
            {
                ans=min(ans,j-i+1);
                
                long long temp=nums[i];
                for(int l=0;l<32;++l)        // Element from the back i.e., i'th element contribution is being taken away
                {
                    int curr=(1&temp);
                    temp/=2;
                    if(curr>0) pre[l]--;
                    
                    if(pre[l]==0 && curr==1) val-=(1LL<<l);
                }   
                i++;
            }
            j++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};