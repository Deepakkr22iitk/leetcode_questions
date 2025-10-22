class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        int curr=0;
        vector<vector<int>>period;
        map<int,int>freq;
        set<int>st;
        for(int i=0;i<len;++i)
        {
            freq[nums[i]]++;
            int l_val=nums[i]-k;
            int h_val=nums[i]+k+1;
            
            period.push_back({l_val,1});
            period.push_back({h_val,-1});
            
            st.insert(nums[i]);
            st.insert(l_val);
            st.insert(h_val);
        }
        
        sort(period.begin(),period.end());
        
        int i=0;
        int n=period.size();
        for(auto &x:st)
        {
            while(i<n && period[i][0]<=x) 
            {
                curr+=period[i][1];
                ++i;
            }
            
            int curr_cnt=0;
            if(freq.find(x)!=freq.end()) curr_cnt=freq[x];
            
            int val=curr_cnt;
            val+=min(numOperations,curr-curr_cnt);
            ans=max(ans,val);
        }
        return ans;
    }
};
