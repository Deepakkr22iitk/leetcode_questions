class Solution {
public:
    int minimumLength(string s) {
       unordered_map<char,int> freq;
       int n=s.size();
       for(int i=0;i<n;++i)
       {
            freq[s[i]]++;
       }
       int ans=0; 
       for(auto &it:freq)
       {
            if(it.second>2)
            {
                if(it.second%2) ans+=1;
                else ans+=2;
            } 
            else ans+=it.second;
       }
       return ans;
    }
};