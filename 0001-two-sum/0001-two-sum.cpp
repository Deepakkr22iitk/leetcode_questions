class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,vector<int>> mp; // num,idx
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        int i=0,j=n-1;
        sort(nums.begin(),nums.end());
        while(i<j && nums[i]+nums[j]!=target)
        {
            if((nums[i]+nums[j])>target) j--;
            else if((nums[i]+nums[j])<target) i++;
        }
        if(nums[i]==nums[j]) return mp[nums[i]];
        vector<int> ans;
        int start=mp[nums[i]][0];
        int end=mp[nums[j]][0];
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};