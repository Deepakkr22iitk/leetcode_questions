class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> nge;
        stack<int> st;
        for(int i=n-1;i>=0;--i)
        {
            while(!st.empty() && st.top()<=nums2[i]) st.pop();

            if(!st.empty()) nge[nums2[i]]=st.top();

            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++)
        {
            if(nge.find(nums1[i])!=nge.end()) ans[i]=nge[nums1[i]];
        }
        
        return ans;
    }
};