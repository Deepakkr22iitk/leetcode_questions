class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        if(k>(n/3)) return -1;
        map<char,int>rk;
        for(auto x:s) rk[x]++;
        
        if(rk['a']<k) return -1;
        if(rk['b']<k) return -1;
        if(rk['c']<k) return -1;
        rk['a']-=k;
        rk['b']-=k;
        rk['c']-=k;
        int i=0;
        int j=0;
        int ans=0;
        map<char,int>dk;
        while(j<n)
        {
            char ch=s[j];
            dk[ch]++;
            
            while(dk['a']>rk['a'] || dk['b']>rk['b'] || dk['c']>rk['c'])
            {
                dk[s[i]]--;
                i++;
            }
            ans=max(ans,(j-i+1));
            j++;
        }
        return n-ans;
    }
};