class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        set<int>st; 
        for(auto &x: nums) st.insert(x);   
        int front=0,back=0,ans=0;
        int n=nums.size();
        while(front<n)
        {
            mp[nums[front]]++;
            while(back<=front && mp.size() == st.size())
            {
                ans+=(n-front); // we can directly add all the different subarrays ahead of our front...because we are sure that there won't be a new unique element afterwards.
                if(--mp[nums[back]]==0) mp.erase(nums[back]); 
                back++; 
            }
            front++;
        }
        return ans;
    }
};