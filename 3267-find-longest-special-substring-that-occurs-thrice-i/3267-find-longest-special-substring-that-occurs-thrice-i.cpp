class Solution {
public:
    // s=aaaaabbaaaacbaa taking this as an example
    int maximumLength(string s) {
        int ans=0;
        int n=s.size();
        unordered_map<int,vector<int>>dee; 
        // corresponding dee map will be
        // (for a) [0]->5,4,2;
        // (for b) [1]->2,1;
        // (for c) [2]->1;
        for(int i=0;i<n;++i)
        {
            int len=i;
            while(len<n && s[len]==s[i])
            {
                len++;
            }
            int curr=len-i;
            dee[s[i]-'a'].push_back(curr);
            i=len-1;
        }
        
        for(auto &rk:dee)
        {
            auto v=rk.second;
            int len=v.size();
            sort(v.begin(),v.end());
            if(len>=2) 
            {
                // in case where we have a vector -> [4,6]
                // then we can't take 4 as our ans v[len-1] as it may be the possibility 
                // that v[len]==v[len-1] so in that case we will be able to have only 2 occurences
                // so but if we take ans=4-1=3 then from last we can have 2 occurences 
                // and from the second last which is greater than that we can have 
                // atleast 1 occurence as we are taking min of them

                int curr=min(v[len-1]-1,v[len-2]);
                ans=max(ans,curr);
            }
            if(len>=3)
            {
                // here is the direct ans v[len-2]
                ans=max(ans,v[len-3]);
            }
            ans=max(v[len-1]-2,ans);
        }
        
        if(ans==0) return -1;
        return ans;
    }
};