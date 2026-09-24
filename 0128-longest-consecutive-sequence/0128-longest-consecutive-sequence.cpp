// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();

//         unordered_map<int,int> len;
//         set<int> st;
//         int ans=0;
//         for(int i=0;i<n;++i)
//         {
//             if(st.find(nums[i])==st.end())
//             {
//                 len[nums[i]]++;
//                 len[nums[i]]+=len[nums[i]+1];
//                 len[nums[i]]+=len[nums[i]-1];
//                 int x=nums[i];
//                 while(st.find(x+1)!=st.end()) 
//                 {
//                     len[x+1]=len[nums[i]];
//                     x++;
//                 }
//                 x=nums[i];
//                 while(st.find(x-1)!=st.end()) 
//                 {
//                     len[x-1]=len[nums[i]];
//                     x--;
//                 }
//                 ans=max(ans,len[nums[i]]);
//                 st.insert(nums[i]);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int process(unordered_map<int,int> &m1, unordered_map<int,int> &vis, int x) {
        if(m1.find(x) == m1.end())
            return 0;
        if(vis.find(x) != vis.end())
            return vis[x];
        vis[x] = process(m1, vis, x+1) + 1;
        return vis[x];
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m1, vis;

        for(int i=0; i<nums.size(); i++)
            m1[nums[i]] = 1;
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
            if(vis.find(nums[i]) == vis.end()) {
                int maxlen = process(m1, vis, nums[i]);
                ans = max(ans, maxlen);
            }
        return ans;
    }
};