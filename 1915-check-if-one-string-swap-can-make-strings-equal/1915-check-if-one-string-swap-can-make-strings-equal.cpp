class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n!=m) return false;

        bool flag=false;
        for(int i=0;i<n;++i)
        {
            if(s1[i]!=s2[i]) 
            {
                if(flag==true) return false;

                int j=i+1;
                while(j<n && s1[j]==s2[j]) j++;

                if(j==n) return false;

                if(s1[i]==s2[j] && s2[i]==s1[j]) flag=true;

                else return false;

                i=j;
            }
        }
        return true;
    }
};