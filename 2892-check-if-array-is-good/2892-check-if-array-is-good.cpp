class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        int tot=(n*(n+1))/2;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>n) return false;
            st.insert(nums[i]);
            tot-=nums[i];
        }
        return (st.size()==n-1 && tot==1);
    }
};