class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;++i)
        {
            if(nums[i]<k) return -1;
            else if(nums[i]>k) st.insert(nums[i]);
        }
        return st.size();
    }
};