class Solution {
public:
    string mirror(string s)
    {
        int m=s.size();
        int i=0,j=m-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n<4) return s;

        string start="";
        string middle="";

        sort(s.begin(),s.end());

        for(int i=0;i<n;i+=2)
        {
            if(s[i]==s[i+1])start+=s[i]; 
            else 
            {
                middle+=s[i];
                i--;
            }
        }

        string ans="";
        // if(n%2==0)
        // {
        //     ans+=start;
        //     ans+=mirror(start);
        // }

        ans+=start;
        if(n%2==1) ans+=middle;
        ans+=mirror(start);
        return ans;
    }
};