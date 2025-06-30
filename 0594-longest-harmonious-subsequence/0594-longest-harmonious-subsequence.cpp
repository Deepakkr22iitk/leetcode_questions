class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        map<int,int>freq;
        for(int i=0;i<n;++i) freq[nums[i]]++;

        auto it=freq.begin();
        while(it!=freq.end())
        {
            auto it2=it;
            it2++;
            if(it2==freq.end()) return ans;
            if((it->first +1)!=it2->first)
            {
                it++;
                continue;
            }
            int freq1=it->second;
            int freq2=it2->second;
            int curr=freq1+freq2;
            ans=max(ans,curr);
            it++;
        }
        return ans;
    }
};