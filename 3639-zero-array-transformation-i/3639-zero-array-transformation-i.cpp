class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        vector<int> v(n+1);
        int now=0;
        for(int i=0;i<q;i++)
        {
            v[queries[i][0]]++;
            v[queries[i][1]+1]--;
        }

        for(int i=0;i<n;i++)
        {
            now+=v[i];
            if(nums[i]>0 && nums[i]>now) return false;
        }
        return true;
    }
};