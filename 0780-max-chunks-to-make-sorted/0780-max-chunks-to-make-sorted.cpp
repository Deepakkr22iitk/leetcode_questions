class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        set<int> st;
        int first=0;
        for(int i=0;i<n;++i)
        {
            st.insert(arr[i]);
            int sz=st.size();
            auto it=st.end();
            it--;
            int last=*it;
            if(sz==(last-first+1)) 
            {
                ans++;
                first=last+1;
                st.clear();
            }
        }
        return ans;
    }
};