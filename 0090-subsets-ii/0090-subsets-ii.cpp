class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);++i)
        {
            vector<int> temp;
            for(int j=0;j<n;++j)
            {
                if((i&(1<<j))!=0) temp.push_back(nums[j]);
            }
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};