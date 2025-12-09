class Solution {
public:
    long long mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int> freqPrev, freqNext;
        int n=nums.size();
        for(int i=1;i<n;++i)
        {
            freqNext[nums[i]]++;
        }
        for(int i=1;i<n-1;++i)
        {
            freqPrev[nums[i-1]]++;
            freqNext[nums[i]]--;

            int req=nums[i]*2;
            ans=(ans + 1LL*freqPrev[req]*freqNext[req]) % mod;
        }
        return ans;
    }
};