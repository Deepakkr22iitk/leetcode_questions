class Solution {
public:
    string reverse(string t,int s,int e)
    {
        while(s<e)
        {
            swap(t[s],t[e]);
            s++;
            e--;
        }
        return t;
    }
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n<3) return s;
        sort(s.begin(),s.end());
        string ans="";
        int ind=-1;
        for(int i=0;i<n;i+=2)
        {
            if(s[i]==s[i+1]) ans+=s[i];
            else 
            {
                ind=i;
                i--;
            }
        }

        if(ind==-1) ans+=reverse(ans,0,ans.size()-1);
        else 
        {
            string res=reverse(ans,0,ans.size()-1);
            ans+=s[ind];
            ans+=res;
        }

        return ans;
    }
};