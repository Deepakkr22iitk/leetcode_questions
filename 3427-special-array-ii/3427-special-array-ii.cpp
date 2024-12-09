class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>val;
        val.push_back(0);
        int curr=0;
        for(int i=1;i<n;++i)
        {
            if((nums[i]%2) == (nums[i-1]%2)) curr++;            // 5,4,6,4,3,8,2,6,5,2,1,8
            val.push_back(curr);                            // 0,0,1,2,2,2,3,4,4,4,4,4
        }
        
        vector<bool>ans;
        for(auto &x:queries)
        {
            if(val[x[0]]==val[x[1]]) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};