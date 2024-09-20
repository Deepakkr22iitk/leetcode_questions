class Solution {
public:
    //Using KMP Algorithm, we can find the longest prefix which is part of the substring 
    // Idea is we need to only append those remaining part from the given string apart from being longest palindrome
    // starting from index '0'
    vector<int>KMP(string &s)
    {
        int len=s.size();
        vector<int>ans(len);

        int comm=0;

        for(int i=1;i<len;++i)
        {
            while(comm>0 && s[i]!=s[comm]) comm=ans[comm-1];
            
            if(s[i]==s[comm]) comm++;

            ans[i]=comm;
        }
        return ans;
    }
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());

        string comb=s+'#'+rev;

        vector<int>prefix=KMP(comb);

        int len=comb.size();
        int longest_palin=prefix[len-1];

        int n=s.size();

        string suff=rev.substr(0,(n-longest_palin));

        return (suff+s);
    }
};