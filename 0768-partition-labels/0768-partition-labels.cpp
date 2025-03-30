class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int>mp;
        int n=s.size();
        for(int i=0;i<n;++i) 
        {
            int ind=s[i]-'a';
            mp[ind]=i;
        }

        vector<int>ans;
        int prev=-1;
        int mx=0;

        for(int i=0;i<n;++i)
        {
            mx=max(mx,mp[s[i]-'a']);
            if(mx==i)
            {
                ans.push_back(i-prev);
                prev=i;
            }
        }
        return ans;
    }
};