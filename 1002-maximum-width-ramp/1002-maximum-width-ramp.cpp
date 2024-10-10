class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans=0;
        stack<int>st;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            if(st.size()==0 || nums[i]<nums[st.top()]) st.push(i);
        }

        for(int i=n-1;i>=0;--i)
        {
            while(!st.empty() && nums[i]>=nums[st.top()])
            {
                int temp=(i-st.top());
                ans=max(ans,temp);
                st.pop();
            }
        }
        return ans;
    }
};