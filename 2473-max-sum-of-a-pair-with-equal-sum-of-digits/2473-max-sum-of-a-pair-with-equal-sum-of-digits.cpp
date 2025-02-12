class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int len=nums.size();
        map<int,vector<int>> equal_sums;
        for(int i=0;i<len;++i)
        {
            int val=nums[i];
            int sum=0;
            while(val)
            {
                sum+=val%10;
                val/=10;
            }
            equal_sums[sum].push_back(nums[i]);
        }

        int ans=-1;
        for(auto &x:equal_sums)
        {
            int len=x.second.size();
            if(len==1) continue;
            sort(x.second.begin(),x.second.end());

            int curr=x.second[len-1]+x.second[len-2];
            ans=max(ans,curr);
        }
        return ans;
    }
};