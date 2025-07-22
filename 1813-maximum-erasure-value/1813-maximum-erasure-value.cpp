class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        int sum=0;
        int ans=0;
        int L=0;
        int R=0;
        
        while(R<n) 
        {
            int right=nums[R++];
            sum+=right;
            mp[right]++;
            
            while(mp[right]>1) //Since, we are always ensuring that freq is never >1.
            {
                int left=nums[L++];
                mp[left]--;
                sum-=left;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};