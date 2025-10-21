class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        int mnm=nums[0]-k;
        int mxm=nums[len-1]+k+5;
        int offset=0;
        if(k>nums[0]) offset=k-nums[0]+1;
        vector<int>freq(mxm+5);
        
        vector<int>cnt(mxm+5);
        int i=0;
        int ans=0;
        while(i<len) 
        {
            cnt[nums[i]]++;
            i++;
        }
        freq[0]=cnt[0];
        for(int i=1;i<mxm;++i)
        {
            freq[i]=freq[i-1]+cnt[i];
        }
        
        int curr_val=0;
        for(int i=0;i<=(nums[len-1]+k+4);++i)
        {
            if(cnt[i]==0 && numOperations==0) continue;
            
            int l_value=max(i-k,0);
            int h_value=min(mxm-1,i+k);
            int curr_len=freq[h_value];
            
            if(l_value!=0) curr_len-=freq[l_value-1];
            
            int allowed=curr_len;
            allowed-=cnt[i];
            curr_val=min(allowed,numOperations);
            curr_val+=cnt[i];
            ans=max(ans,curr_val);
        }
        return ans;
    }
};